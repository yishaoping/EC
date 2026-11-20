// SPDX-License-Identifier: GPL-2.0
/* Real MMIO-backed ROI control. No emulation, timestamp fallback or success
 * stub. The device tree and target controller are separate prerequisites.
 * Version 3 generated hardware has neither; this driver cannot bind there.
 * Initial implementation accepts B only. C4 also needs an mmu-notifier and
 * firmware/context protocol before a checker may access a Linux address space.
 */
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/io.h>
#include <linux/kref.h>
#include <linux/miscdevice.h>
#include <linux/mm.h>
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
	enum dac_session session;
};
struct dac_reply {
	u64 state, epoch, begin, end, drain, outstanding, generated, completed, faults;
};

static u64 dac_read(struct dac_device *d, unsigned int reg)
{
	return readq(d->regs + reg);
}
static void dac_forget_owner(struct dac_device *d)
{
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
	if (d->mm)
		pr_err("ec_dac_roi: quarantining mm after missing drain; reset required\n");
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
	d->mm = current->mm;
	mmget(d->mm);
	d->owner = current;
	get_task_struct(d->owner);
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
	if (r.faults || r.end <= r.begin ||
	    (cmd == EC_DAC_END && r.state != DAC_HW_ENDED) ||
	    (cmd == EC_DAC_DRAIN && (r.state != DAC_HW_DRAINED || r.drain < r.end || !dac_clean(&r))) ||
	    (!d->checkers && (r.generated || r.completed || r.outstanding))) {
		ret = -EPROTO;
		goto out;
	}
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
static const struct file_operations dac_fops = {
	.owner = THIS_MODULE,
	.open = dac_open,
	.release = dac_release,
	.unlocked_ioctl = dac_ioctl,
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
	if (d->checkers) {
		dev_err(&pdev->dev, "checker Linux mm/context protocol not implemented; refusing bind\n");
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
