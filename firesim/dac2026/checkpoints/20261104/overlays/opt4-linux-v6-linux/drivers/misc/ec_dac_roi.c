// SPDX-License-Identifier: GPL-2.0
/* C4 version 6 Linux integration. Uses the original Opt4 task/replay/compare
 * hardware and an RX U-mode service in the retained BOOM address space.
 * Single process, one thread, one ROI per boot. Kernel execution, exceptions,
 * address-space changes and asynchronous cancellation are not supported by
 * this first entry. A live mapping invalidation is held, never passed off. */
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/io.h>
#include <linux/kref.h>
#include <linux/miscdevice.h>
#include <linux/mm.h>
#include <linux/mmu_notifier.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/sched.h>
#include <linux/sched/mm.h>
#include <linux/sched/signal.h>
#include <linux/sched/task.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <asm/csr.h>
#include <asm/smp.h>
#include <asm/sbi.h>
#include <asm/ptrace.h>
#include "opt4_hw.h"
#include "ec_opt4_service_blob.h"
#include "ec_dac_roi_regs.h"
#include "ec_dac_roi_uapi.h"

#define DAC_COMMAND_TIMEOUT_MS 30000
enum dac_session { DAC_CLOSED, DAC_OPEN, DAC_ARMED, DAC_ENDED, DAC_FINISHED, DAC_BAD };
struct dac_device {
	struct miscdevice misc;
	struct mutex lock;
	struct kref ref;
	void __iomem *regs;
	bool connected, opened, poisoned;
	u64 caps, checkers, epoch, token;
	struct mm_struct *mm; /* Retain the page tables until a genuine drain ACK. */
	struct task_struct *owner;
	u64 satp;
	unsigned long service_va;
	struct page *service_page;
	struct mmu_notifier notifier;
	bool notifier_registered, context_started;
	enum dac_session session;
};
struct dac_reply {
	u64 state, epoch, begin, end, drain, outstanding, generated, completed, faults;
};

static u64 dac_read(struct dac_device *d, unsigned int reg)
{
	return readq(d->regs + reg);
}
#define EC_OPT4_EXT 0x08004f50
#define EC_DAC_QUERY_CHECKERS _IOR('E', 0x73, __u64)
static u64 dac_firmware_status(void)
{
	struct sbiret r = sbi_ecall(EC_OPT4_EXT, 2, 0, 0, 0, 0, 0, 0);
	return r.error ? U64_MAX : r.value;
}
static bool dac_context_idle(struct dac_device *d)
{
	return !d->context_started || dac_firmware_status() == 15;
}
static int dac_invalidate(struct mmu_notifier *mn, const struct mmu_notifier_range *range)
{
	struct dac_device *d = container_of(mn, struct dac_device, notifier);
	if (dac_context_idle(d))
		return 0;
	if (!mmu_notifier_range_blockable(range))
		return -EAGAIN;
	WRITE_ONCE(d->poisoned, true);
	pr_err("EC_OPT4_INVALID reason=mm_invalidation action=hold_page_tables_until_real_checker_park reset_may_be_required\n");
	/* An unsupported mapping change cannot free page tables under a live PTW.
	 * Version 6 has no asynchronous cancellation. Hold the invalidation until
	 * the REAL service has parked, including its satp clear and sfence.vma.
	 * This may intentionally block an unsupported sample; it never reports PASS. */
	while (!dac_context_idle(d))
		msleep(10);
	return 0;
}
static const struct mmu_notifier_ops dac_mmu_ops = {
	.invalidate_range_start = dac_invalidate,
};
static void dac_forget_owner(struct dac_device *d)
{
	if (!dac_context_idle(d)) {
		d->poisoned = true;
		pr_err("EC_OPT4_INVALID reason=context_live action=quarantine_mm\n");
		return;
	}
	if (d->notifier_registered) {
		mmu_notifier_unregister(&d->notifier, d->mm);
		d->notifier_registered = false;
	}
	if (d->owner) {
		put_task_struct(d->owner);
		d->owner = NULL;
	}
	if (d->mm) {
		mmput(d->mm);
		d->mm = NULL;
	}
}
static void dac_free(struct kref *ref)
{
	struct dac_device *d = container_of(ref, struct dac_device, ref);
	/* A disconnected controller with uncertain drain must retain its mm ref.
	 * Never free page tables while a checker could still walk them. */
	if (d->mm) {
		pr_err("ec_dac_roi: quarantining mm after missing drain; reset required\n");
		return; /* Keep embedded notifier and device alive with quarantined mm. */
	}
	if (d->owner)
		put_task_struct(d->owner);
	kfree(d);
}

/* A new token commits the complete request after the data writes. ABORT must
 * preempt/cancel an unacknowledged prior command and be idempotent per epoch.
 * ACK is published only AFTER all reply registers are frozen. */
static int dac_command(struct dac_device *d, unsigned int command, struct dac_reply *r)
{
	unsigned long deadline = jiffies + msecs_to_jiffies(DAC_COMMAND_TIMEOUT_MS);
	u64 token;
	if (!d->connected)
		return -ENODEV;
	if (d->token >= (U64_MAX >> 8))
		return -EOVERFLOW;
	token = (++d->token << 8) | command;
	writeq(d->epoch, d->regs + DAC_REQUEST_EPOCH);
	writeq(d->satp, d->regs + DAC_REQUEST_SATP);
	writeq(0, d->regs + DAC_REQUEST_HART);
	wmb();
	writeq(token, d->regs + DAC_COMMAND);
	while (dac_read(d, DAC_ACK) != token) {
		if (time_after_eq(jiffies, deadline))
			return -ETIMEDOUT;
		if (command != DAC_CMD_ABORT && fatal_signal_pending(current))
			return -EINTR;
		usleep_range(100, 200);
	}
	if (dac_read(d, DAC_ERROR))
		return -EIO;
	r->state = dac_read(d, DAC_STATE);
	r->epoch = dac_read(d, DAC_EPOCH);
	r->begin = dac_read(d, DAC_BEGIN_TICK);
	r->end = dac_read(d, DAC_END_TICK);
	r->drain = dac_read(d, DAC_DRAIN_TICK);
	r->outstanding = dac_read(d, DAC_OUTSTANDING);
	r->generated = dac_read(d, DAC_GENERATED);
	r->completed = dac_read(d, DAC_COMPLETED);
	r->faults = dac_read(d, DAC_FAULTS);
	if (dac_read(d, DAC_ACK) != token || r->epoch != d->epoch)
		return -EPROTO;
	return 0;
}
static bool dac_clean(const struct dac_reply *r)
{
	return !r->outstanding && r->generated == r->completed;
}
static int dac_abort(struct dac_device *d)
{
	struct dac_reply r;
	int ret = dac_command(d, DAC_CMD_ABORT, &r);
	/* ABORT invalidates the sample and may cancel tasks. Equality of PASS
	 * counts is required for normal DRAIN, not for cancelling a failed sample. */
	if (!ret && (r.outstanding || (r.state != DAC_HW_DRAINED && r.state != DAC_HW_IDLE)))
		ret = -EPROTO;
	d->poisoned = !!ret;
	if (!ret)
		dac_forget_owner(d);
	return ret;
}

static int dac_open(struct inode *inode, struct file *file)
{
	struct dac_device *d = container_of(file->private_data, struct dac_device, misc);
	int ret = 0;
	mutex_lock(&d->lock);
	if (!d->connected)
		ret = -ENODEV;
	else if (d->opened)
		ret = -EBUSY;
	else if (d->poisoned)
		ret = dac_abort(d);
	if (!ret) {
		d->opened = true;
		d->session = DAC_OPEN;
		kref_get(&d->ref);
		file->private_data = d;
	}
	mutex_unlock(&d->lock);
	return ret;
}
static int dac_release(struct inode *inode, struct file *file)
{
	struct dac_device *d = file->private_data;
	mutex_lock(&d->lock);
	if (d->mm && d->session != DAC_FINISHED)
		dac_abort(d); /* A failed abort quarantines mm; next BEGIN is blocked. */
	else
		dac_forget_owner(d);
	d->session = DAC_CLOSED;
	d->opened = false;
	mutex_unlock(&d->lock);
	kref_put(&d->ref, dac_free);
	return 0;
}
static int dac_begin(struct dac_device *d, struct ec_dac_boundary *b)
{
	struct dac_reply r;
	struct sbiret fw;
	struct vm_area_struct *vma;
	unsigned long deadline;
	int ret;
	if (d->session != DAC_OPEN || d->mm || b->epoch)
		return -EBUSY;
	/* Linux is intentionally uniprocessor. Checker harts MUST be reserved by
	 * firmware/DT; no affinity change or hotplug is done by this driver. */
	if (!current->mm || num_online_cpus() != 1 || task_cpu(current) != 0 ||
	    cpuid_to_hartid_map(0) != 0)
		return -EXDEV;
	if (d->epoch == U64_MAX)
		return -EOVERFLOW;
	d->satp = csr_read(CSR_SATP);
	if (!(d->satp >> 60))
		return -EINVAL;
	if (d->context_started || get_nr_threads(current) != 1 || !d->service_va)
		return -EOPNOTSUPP;
	mmap_read_lock(current->mm);
	vma = find_vma(current->mm, d->service_va);
	ret = !vma || vma->vm_start != d->service_va ||
		!vma->vm_file || vma->vm_file->private_data != d ||
		!(vma->vm_flags & VM_EXEC) || (vma->vm_flags & VM_WRITE);
	mmap_read_unlock(current->mm);
	if (ret)
		return -EXDEV;
	d->mm = current->mm;
	mmget(d->mm);
	d->owner = current;
	get_task_struct(d->owner);
	d->notifier.ops = &dac_mmu_ops;
	ret = mmu_notifier_register(&d->notifier, d->mm);
	if (ret) { dac_forget_owner(d); return ret; }
	d->notifier_registered = true;
	/* Linux start_thread clears XS. Enable RoCC in both the current S context
	 * and the saved U return context before issuing any custom instruction. */
	csr_set(CSR_STATUS, SR_XS);
	task_pt_regs(current)->status |= SR_XS;
	ec_opt4_configure();
	/* Establish the BOOM monitor in its current mm before returning to U.
	 * Normal user tasks use the unmodified CPS/ECP context protocol. */
	EC_SET(0x16, 1);
	ec_perf(1);
	ec_perf(1UL << 5);
	fw = sbi_ecall(EC_OPT4_EXT, 1, d->satp, d->service_va, 0, 0, 0, 0);
	if (fw.error || fw.value != 1) { dac_forget_owner(d); return -EIO; }
	d->context_started = true;
	deadline = jiffies + msecs_to_jiffies(DAC_COMMAND_TIMEOUT_MS);
	while (!EC_RD(0x1b, 0)) {
		if (time_after_eq(jiffies, deadline)) return -ETIMEDOUT;
		usleep_range(100, 200);
	}
	for (unsigned long hart = 1; hart <= 4; ++hart) {
		fw = sbi_ecall(EC_OPT4_EXT, 3, hart, 0, 0, 0, 0, 0);
		if (fw.error || fw.value != d->satp)
			return -EPROTO;
		pr_info("EC_OPT4_INSTALLED hart=%lu satp=%016lx\n", hart, fw.value);
	}
	pr_info("EC_OPT4_CONTEXT version=6 checkers=4 hart=0 satp=%016llx service_va=%lx hardware_initialized=1 scope=user_no_trap_one_mm\n",
		d->satp, d->service_va);
	++d->epoch;
	d->session = DAC_BAD; /* An uncertain ARM always requires ABORT. */
	ret = dac_command(d, DAC_CMD_ARM, &r);
	if (ret)
		return ret;
	if (r.state != DAC_HW_ARMED || !dac_clean(&r) || r.generated || r.faults)
		return -EPROTO;
	d->session = DAC_ARMED;
	b->epoch = d->epoch;
	b->target_tick = 0; /* The userspace begin marker has NOT executed yet. */
	b->outstanding = 0;
	b->status = 0;
	return 0;
}
static long dac_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct dac_device *d = file->private_data;
	struct ec_dac_boundary b;
	struct dac_reply r;
	int ret;
	if (cmd == EC_DAC_QUERY_CHECKERS) {
		__u64 count = 4;
		return copy_to_user((void __user *)arg, &count, sizeof(count)) ? -EFAULT : 0;
	}
	if (cmd != EC_DAC_BEGIN && cmd != EC_DAC_END && cmd != EC_DAC_DRAIN)
		return -ENOTTY;
	if (copy_from_user(&b, (void __user *)arg, sizeof(b)))
		return -EFAULT;
	if (b.version != DAC_ABI_VERSION)
		return -EPROTONOSUPPORT;
	if (mutex_lock_interruptible(&d->lock))
		return -ERESTARTSYS;
	if (!d->connected) {
		ret = -ENODEV;
		goto out;
	}
	if (cmd == EC_DAC_BEGIN) {
		ret = dac_begin(d, &b);
		goto copy;
	}
	if (d->owner != current || d->mm != current->mm || b.epoch != d->epoch ||
	    csr_read(CSR_SATP) != d->satp) {
		ret = -EXDEV;
		goto out;
	}
	if ((cmd == EC_DAC_END && d->session != DAC_ARMED) ||
	    (cmd == EC_DAC_DRAIN && d->session != DAC_ENDED)) {
		ret = -EPROTO;
		goto out;
	}
	d->session = DAC_BAD;
	ret = dac_command(d, cmd == EC_DAC_END ? DAC_CMD_END : DAC_CMD_DRAIN, &r);
	if (ret)
		goto out;
	pr_info("EC_OPT4_SNAPSHOT epoch=%llu command=%u begin=%llu end=%llu drain=%llu generated=%llu completed=%llu outstanding=%llu faults=%llu passed=%lu failed=%lu cancelled=%lu dropped=%lu firmware=%llx\n",
		r.epoch, cmd, r.begin, r.end, r.drain, r.generated, r.completed,
		r.outstanding, r.faults, ec_traffic(32), ec_traffic(22),
		ec_traffic(33), ec_traffic(27), dac_firmware_status());
	if (cmd == EC_DAC_DRAIN) {
		unsigned long deadline = jiffies + msecs_to_jiffies(DAC_COMMAND_TIMEOUT_MS);
		while (!dac_context_idle(d) && !d->poisoned) {
			if (time_after_eq(jiffies, deadline)) { ret = -ETIMEDOUT; goto out; }
			usleep_range(100, 200);
		}
		if (d->poisoned || !dac_context_idle(d)) { ret = -EIO; goto out; }
	}
	if (r.faults || r.end <= r.begin ||
	    (cmd == EC_DAC_END && r.state != DAC_HW_ENDED) ||
	    (cmd == EC_DAC_DRAIN && (r.state != DAC_HW_DRAINED || r.drain < r.end || !dac_clean(&r))) ||
	    (!d->checkers && (r.generated || r.completed || r.outstanding))) {
		ret = -EPROTO;
		goto out;
	}
	/* AFTER the real firmware park readback and all controller checks.
	 * The earlier SNAPSHOT may still show a partial firmware mask. */
	if (cmd == EC_DAC_DRAIN)
		pr_info("EC_OPT4_CONTEXT_DRAINED epoch=%llu firmware=%llx satp=%016llx generated=%llu completed=%llu outstanding=%llu\n",
			r.epoch, dac_firmware_status(), d->satp,
			r.generated, r.completed, r.outstanding);
	d->session = cmd == EC_DAC_END ? DAC_ENDED : DAC_FINISHED;
	b.target_tick = cmd == EC_DAC_END ? r.end : r.drain;
	b.outstanding = r.outstanding;
	b.status = 0;
copy:
	if (!ret && copy_to_user((void __user *)arg, &b, sizeof(b))) {
		d->session = DAC_BAD;
		ret = -EFAULT;
	}
out:
	mutex_unlock(&d->lock);
	return ret;
}
static int dac_mmap(struct file *file, struct vm_area_struct *vma)
{
	struct dac_device *d = file->private_data;
	int ret;
	if (vma->vm_end-vma->vm_start != PAGE_SIZE || vma->vm_pgoff ||
	    !(vma->vm_flags & VM_EXEC) || (vma->vm_flags & VM_WRITE) ||
	    !(vma->vm_flags & VM_SHARED))
		return -EINVAL;
	mutex_lock(&d->lock);
	if (!d->connected || d->context_started || d->service_va) {
		ret = -EBUSY;
		goto out;
	}
	vma->vm_flags &= ~(VM_MAYWRITE | VM_MAYEXEC);
	vma->vm_flags |= VM_DONTCOPY | VM_DONTEXPAND | VM_DONTDUMP;
	ret = remap_pfn_range(vma, vma->vm_start, page_to_pfn(d->service_page),
		PAGE_SIZE, vma->vm_page_prot);
	if (!ret) d->service_va = vma->vm_start;
out:
	mutex_unlock(&d->lock);
	return ret;
}
static const struct file_operations dac_fops = {
	.owner = THIS_MODULE,
	.open = dac_open,
	.release = dac_release,
	.unlocked_ioctl = dac_ioctl,
	.mmap = dac_mmap,
	.llseek = no_llseek,
};

static int dac_probe(struct platform_device *pdev)
{
	struct dac_device *d;
	struct resource *res;
	u64 required;
	int ret;
	BUILD_BUG_ON(sizeof(struct ec_dac_boundary) != 40);
	if (!IS_ENABLED(CONFIG_64BIT) || !IS_ENABLED(CONFIG_RISCV) || IS_ENABLED(CONFIG_SMP))
		return -EOPNOTSUPP;
	d = kzalloc(sizeof(*d), GFP_KERNEL);
	if (!d)
		return -ENOMEM;
	kref_init(&d->ref);
	mutex_init(&d->lock);
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res || resource_size(res) < DAC_REGISTER_BYTES) {
		ret = -EINVAL;
		goto free;
	}
	d->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(d->regs)) {
		ret = PTR_ERR(d->regs);
		goto free;
	}
	if (dac_read(d, DAC_MAGIC) != DAC_MAGIC_VALUE || dac_read(d, DAC_VERSION) != DAC_ABI_VERSION) {
		ret = -EPROTONOSUPPORT;
		goto free;
	}
	d->caps = dac_read(d, DAC_CAPS);
	d->checkers = dac_read(d, DAC_CHECKERS);
	if (d->checkers != 4 || sbi_ecall(EC_OPT4_EXT, 0, 0, 0, 0, 0, 0, 0).value != 0x60004) {
		dev_err(&pdev->dev, "C4 version 6 hardware/firmware required\n");
		ret = -EOPNOTSUPP;
		goto free;
	}
	required = DAC_CAP_COMMON | (d->checkers ? DAC_CAP_CORRECTION |
		DAC_CAP_EXEC_COMPARE | DAC_CAP_LINUX_CONTEXT : DAC_CAP_BASELINE);
	if ((d->caps & required) != required ||
	    (d->checkers && d->checkers != 2 && d->checkers != 4 && d->checkers != 8) ||
	    (!!(d->caps & DAC_CAP_BASELINE) == !!(d->caps & DAC_CAP_CORRECTION))) {
		ret = -EOPNOTSUPP;
		goto free;
	}
	d->epoch = dac_read(d, DAC_EPOCH);
	d->token = dac_read(d, DAC_ACK) >> 8;
	/* Recover an uncertain prior session only through an actual drain ACK. */
	d->poisoned = dac_read(d, DAC_STATE) != DAC_HW_IDLE || dac_read(d, DAC_OUTSTANDING);
	d->connected = true;
	d->service_page = alloc_page(GFP_KERNEL | __GFP_ZERO);
	if (!d->service_page) { ret = -ENOMEM; goto free; }
	memcpy(page_address(d->service_page), ec_opt4_service_blob, sizeof(ec_opt4_service_blob));
	d->misc.minor = MISC_DYNAMIC_MINOR;
	d->misc.name = "ec_dac_roi";
	d->misc.fops = &dac_fops;
	d->misc.parent = &pdev->dev;
	d->misc.mode = 0600;
	ret = misc_register(&d->misc);
	if (ret)
		goto free;
	platform_set_drvdata(pdev, d);
	return 0;
free:
	kref_put(&d->ref, dac_free);
	return ret;
}
static int dac_remove(struct platform_device *pdev)
{
	struct dac_device *d = platform_get_drvdata(pdev);
	mutex_lock(&d->lock);
	if (d->mm && d->session != DAC_FINISHED)
		dac_abort(d);
	else
		dac_forget_owner(d);
	d->connected = false;
	mutex_unlock(&d->lock);
	misc_deregister(&d->misc);
	kref_put(&d->ref, dac_free);
	return 0;
}
static const struct of_device_id dac_of_match[] = {
	{ .compatible = "ec,dac-roi-v1" }, { }
};
MODULE_DEVICE_TABLE(of, dac_of_match);
static struct platform_driver dac_driver = {
	.probe = dac_probe,
	.remove = dac_remove,
	.driver = {
		.name = "ec_dac_roi",
		.of_match_table = dac_of_match,
		.suppress_bind_attrs = true,
	},
};
module_platform_driver(dac_driver);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("EC DAC source-event ROI control; requires actual target controller");
