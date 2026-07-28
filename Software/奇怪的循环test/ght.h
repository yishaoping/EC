/**
 * @file    ght.h
 * @brief   Guardian Heart Table（GHT）RoCC 控制接口
 *
 * @details 在当前 BOOM + checker 配置中，大核提交事件由 GH_BUF 提取，
 *          GHT/GHE 软件接口负责监控状态、过滤规则、SE 调度、checker
 *          mapper、SATP/特权上下文和初始化握手。历史文件名沿用 ght.h。
 *
 * @warning 本头文件含若干非 static 的函数定义，现有链接脚本依赖
 *          --allow-multiple-definition。新增接口应优先写成 static inline。
 *
 *          主要功能模块：
 *          - 调试计数器：debug_mcounter(), debug_icounter(), debug_gcounter()
 *          - 断点调试：  debug_bp_reset(), debug_bp_checker(), debug_bp_cdc(), debug_bp_filter()
 *          - 状态控制：  ght_set_status(), ght_get_status()
 *          - SATP/权限： ght_get_satp(), ght_get_priv(), ght_set_satp_priv(), ght_unset_satp_priv()
 *          - 过滤器配置：ght_cfg_filter(), ght_cfg_filter_rvc()（RVC压缩指令版本）
 *          - SE 调度：   ght_cfg_se()（执行单元调度配置）
 *          - Mapper：    ght_cfg_mapper()（指令类型到SE的映射）
 *          - 聚合配置：  ghm_cfg_agg()
 *          - 初始化控制：ght_get_initialisation(), ght_set_numberofcheckers()
 *
 *          ROCC 指令编码关键 funct：
 *          funct=0x06:  GHT 状态查询/配置
 *          funct=0x16:  SATP 权限控制
 *          funct=0x17:  获取 SATP
 *          funct=0x18:  获取特权级
 *          funct=0x1b:  获取初始化状态
 *          funct=0x1c:  设置 checker 核数量
 */

#include <stdint.h>

// ==================== 通用宏定义 ====================
#define TRUE      0x01    // 布尔真
#define FALSE     0x00    // 布尔假
#define NUM_CORES 4       // 历史接口常量：checker 数量，不含 hart 0

// ==================== GHT 状态码 ====================
#define GHT_FULL  0x02    // GHT 缓冲区已满
#define GHT_EMPTY 0x01    // GHT 缓冲区为空

// ==================== 调试计数器接口 ====================

/** @brief 通过 funct=0x2d 重置 GHT 断点统计；返回类型为历史遗留。 */
uint64_t debug_bp_reset()
{
    ROCC_INSTRUCTION(1, 0x2d);
}

/** @brief 读取 checker 核断点计数 */
uint64_t debug_bp_checker()
{
    uint64_t bp_checker;
    ROCC_INSTRUCTION_D(1, bp_checker, 0x1d);
    return bp_checker;
}

/** @brief 读取 CDC（跨时钟域）断点计数 */
uint64_t debug_bp_cdc()
{
    uint64_t bp_cdc;
    ROCC_INSTRUCTION_D(1, bp_cdc, 0x1e);
    return bp_cdc;
}

/** @brief 读取过滤器断点计数 */
uint64_t debug_bp_filter()
{
    uint64_t bp_filter;
    ROCC_INSTRUCTION_D(1, bp_filter, 0x1e);
    return bp_filter;
}

/** @brief 读取内存操作计数器 */
static inline uint64_t debug_mcounter()
{
    uint64_t mcounter;
    ROCC_INSTRUCTION_D(1, mcounter, 0x19);
    return mcounter;
}

/** @brief 读取指令计数器 */
static inline uint64_t debug_icounter()
{
    uint64_t icounter;
    ROCC_INSTRUCTION_D(1, icounter, 0x1a);
    return icounter;
}

/** @brief 读取全局事件计数器 */
static inline uint64_t debug_gcounter()
{
    uint64_t icounter;
    ROCC_INSTRUCTION_D(1, icounter, 0x23);
    return icounter;
}

// ==================== GHT 状态控制 ====================

/**
 * @brief  设置 GHT 状态
 * @param  index  状态索引：0=停止, 1=运行, 2=暂停, 3=恢复, 4=重置
 * @note   非 0..4 的值不会发出任何 RoCC 指令。
 */
static inline void ght_set_status(uint64_t index)
{
    if (index == 0) { ROCC_INSTRUCTION(1, 0x30); }
    if (index == 1) { ROCC_INSTRUCTION(1, 0x31); }
    if (index == 2) { ROCC_INSTRUCTION(1, 0x32); }
    if (index == 3) { ROCC_INSTRUCTION(1, 0x33); }
    if (index == 4) { ROCC_INSTRUCTION(1, 0x34); }
}

/**
 * @brief  获取 GHT 当前状态
 * @return GHT 状态码
 */
static inline uint64_t ght_get_status()
{
    uint64_t get_status;
    ROCC_INSTRUCTION_DSS(1, get_status, 0X00, 0X00, 0x06);
    return get_status;
}

// ==================== SATP 和特权级接口 ====================

/** @brief 获取当前 SATP（页表基址）寄存器值 */
static inline uint64_t ght_get_satp()
{
    uint64_t get_satp;
    ROCC_INSTRUCTION_DSS(1, get_satp, 0X00, 0X00, 0x17);
    return get_satp;
}

/** @brief 获取当前特权级 */
static inline uint64_t ght_get_priv()
{
    uint64_t get_priv;
    ROCC_INSTRUCTION_DSS(1, get_priv, 0X00, 0X00, 0x18);
    return get_priv;
}

/** @brief 使能 GuardianCouncil 对 SATP/特权上下文的捕获或恢复控制。 */
static inline void ght_set_satp_priv()
{
    ROCC_INSTRUCTION_S(1, 0x01, 0x16);
}

/** @brief 取消 SATP/特权上下文控制，在主核和 checker 清理阶段调用。 */
static inline void ght_unset_satp_priv()
{
    ROCC_INSTRUCTION_S(1, 0x02, 0x16);
}

// ==================== 缓冲区状态 ====================

/** @brief 获取 GHT 内部缓冲区状态 */
static inline uint64_t ght_get_buffer_status()
{
    uint64_t get_buffer_status;
    ROCC_INSTRUCTION_DSS(1, get_buffer_status, 0X00, 0X00, 0x08);
    return get_buffer_status;
}

// ==================== 指令过滤器配置 ====================

/**
 * @brief  配置 GHT 指令过滤器（标准指令）
 * @param  index    过滤器组 ID（如 0x01=load, 0x02=store, 0x03=CSR）
 * @param  func     用于匹配的 4 位功能字段（通常来自 funct3）
 * @param  opcode   指令操作码
 * @param  sel_d    数据路径选择（如 0x02=LDQ, 0x03=STQ, 0x01=PRFs）
 *
 * @note   编码格式：
 *         bit[31:28] = func[3:0]
 *         bit[27:21] = opcode[6:0]
 *         bit[20:17] = sel_d[3:0]
 *         bit[8:4]   = index[4:0]
 *         bit[1]     = 1 (标准指令标志)
 */
static inline void ght_cfg_filter(uint64_t index, uint64_t func, uint64_t opcode, uint64_t sel_d)
{
    uint64_t set_ref;
    set_ref = ((index & 0x1f) << 4)
            | ((sel_d & 0xf) << 17)
            | ((opcode & 0x7f) << 21)
            | ((func & 0xf) << 28)
            | 0x02;
    ROCC_INSTRUCTION_SS(1, set_ref, 0X02, 0x06);
}

/**
 * @brief  配置 GHT 指令过滤器（RVC 压缩指令）
 * @param  index    过滤器组 ID
 * @param  func     指令的 funct3 字段
 * @param  opcode   压缩指令操作码
 * @param  msb      RVC 指令的 MSB 位
 * @param  sel_d    数据路径选择
 *
 * @note   func 字段 bit3 会被自动置 1 以标记 RVC 指令。
 */
static inline void ght_cfg_filter_rvc(uint64_t index, uint64_t func, uint64_t opcode, uint64_t msb, uint64_t sel_d)
{
    uint64_t set_ref;
    set_ref = ((index & 0x1f) << 4)
            | ((sel_d & 0xf) << 17)
            | (((opcode | ((msb & 1) << 2)) & 0x7f) << 21)
            | (((func | 0x8) & 0xf) << 28)
            | 0x02;
    ROCC_INSTRUCTION_SS(1, set_ref, 0X02, 0x06);
}

// ==================== SE (执行单元) 调度配置 ====================

/**
 * @brief  配置执行单元的调度策略
 * @param  se_id     执行单元 ID（0~3）
 * @param  end_id    该 SE 调度范围的末尾 checker ID
 * @param  policy    调度策略（0x01=轮询 RR）
 * @param  start_id  该 SE 调度范围的起始 checker ID
 */
static inline void ght_cfg_se(uint64_t se_id, uint64_t end_id, uint64_t policy, uint64_t start_id)
{
    uint64_t set_se;
    set_se = ((se_id & 0x1f) << 4)
           | ((start_id & 0xf) << 17)
           | ((policy & 0x7f) << 21)
           | ((end_id & 0xf) << 28)
           | 0x04;
    ROCC_INSTRUCTION_SS(1, set_se, 0X02, 0x06);
}

// ==================== Mapper 配置 ====================

/**
 * @brief  配置指令类型到 SE 的映射关系
 * @param  inst_type          包类别、核心 ID 与快照标志组合后的 8 位编码
 * @param  ses_receiving_inst  接收该指令的 SE 位掩码
 */
static inline void ght_cfg_mapper(uint64_t inst_type, uint64_t ses_receiving_inst)
{
    uint64_t set_mapper;
    set_mapper = ((inst_type & 0xff) << 4)
               | ((ses_receiving_inst & 0xFFFF) << 16)
               | 0x03;
    ROCC_INSTRUCTION_SS(1, set_mapper, 0X02, 0x06);
}

// ==================== 聚合配置 ====================

/**
 * @brief  配置聚合核心 ID
 * @param  agg_core_id  负责聚合结果的核心 ID
 */
static inline void ghm_cfg_agg(uint64_t agg_core_id)
{
    uint64_t agg_core_set;
    agg_core_set = ((agg_core_id & 0xffff) << 16) | 0x08;
    ROCC_INSTRUCTION_SS(1, agg_core_set, 0X02, 0x06);
}

// ==================== 调试宽度配置 ====================

/**
 * @brief  设置调试过滤器的位宽
 * @param  width  位宽值（0=不过滤，其他值限制捕获宽度）
 */
static inline void ght_debug_filter_width(uint64_t width)
{
    uint64_t set_debug_width;
    set_debug_width = ((width & 0xf) << 4) | 0x05;
    ROCC_INSTRUCTION_SS(1, set_debug_width, 0X02, 0x06);
}

// ==================== 空闲循环 ====================

/**
 * @brief  让非主核永久停止执行软件任务。
 * @note   当前实现是忙等而非 WFI；函数不会返回。
 */
void idle()
{
    while (1) {};
}

// ==================== 初始化控制 ====================

/**
 * @brief  查询 GHT 初始化是否完成
 * @return 0=未完成, 非0=已完成
 */
static inline uint64_t ght_get_initialisation()
{
    uint64_t get_status;
    ROCC_INSTRUCTION_D(1, get_status, 0x1b);
    return get_status;
}

/**
 * @brief  设置 checker 核的数量
 * @param  num  checker 核数量；默认测试传入 TEST_NUM_CHECKERS=4
 */
static inline void ght_set_numberofcheckers(uint64_t num)
{
    ROCC_INSTRUCTION_S(1, num, 0x1c);
}


/**
 * @brief  把一个 checker 的事件包和上下文包映射到其专属 SE。
 * @param  core_id checker hart ID，合法范围为 1..4。
 *
 * @details core_id 写入包类别编码的 core 字段，SE 位掩码使用
 *          1 << (core_id - 1)。0x1/0x2/0x3 类别是普通检查包，0x5/0x7
 *          类别用于上下文/快照相关路由；高位组合表示不同方向或阶段。
 */
static inline void r_set_corex_p_s (uint64_t core_id)
{
  // 编码中的 core 字段从 bit 3 开始。
  uint64_t mask = core_id << 3;
  ght_cfg_mapper (0b10000001 | mask, 0b0001 << (core_id - 1));
  ght_cfg_mapper (0b10000010 | mask, 0b0001 << (core_id - 1));
  ght_cfg_mapper (0b10000011 | mask, 0b0001 << (core_id - 1));
  ght_cfg_mapper (0b01000001 | mask, 0b0001 << (core_id - 1));
  ght_cfg_mapper (0b01000010 | mask, 0b0001 << (core_id - 1));
  ght_cfg_mapper (0b01000011 | mask, 0b0001 << (core_id - 1));
  // 快照/上下文相关包路由到同一个 checker SE。
  ght_cfg_mapper (0b10000111 | mask, 0b0001 << (core_id - 1));
  ght_cfg_mapper (0b01000111 | mask, 0b0001 << (core_id - 1));
  ght_cfg_mapper (0b11000111 | mask, 0b0001 << (core_id - 1));


  ght_cfg_mapper (0b10000101 | mask, 0b0001 << (core_id - 1));
  ght_cfg_mapper (0b01000101 | mask, 0b0001 << (core_id - 1));
  ght_cfg_mapper (0b11000101 | mask, 0b0001 << (core_id - 1));
}
