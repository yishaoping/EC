#include "gapbs_bfs.h"

#define out_offset gapbs_small_out_offset
#define in_offset gapbs_small_in_offset
#define out_edge gapbs_small_out_edge
#define in_edge gapbs_small_in_edge
#define parent gapbs_small_parent
#define frontier gapbs_small_frontier
#define next_frontier gapbs_small_next_frontier
#define front_bits gapbs_small_front_bits
#define next_bits gapbs_small_next_bits
#define clear_bits gapbs_small_clear_bits
#define copy_bits gapbs_small_copy_bits
#define count_out_edges gapbs_small_count_out_edges
#define bottom_up_step gapbs_small_bottom_up_step
#define top_down_step gapbs_small_top_down_step
#define verify_result gapbs_small_verify_result

/*
 * GAPBS 最小小图版本：该 CSR 数据由 GAPBS test/graphs/4.el 预生成，
 * 提供给裸机 benchmark 做快速功能验证。
 */
#define GAPBS_NODE_COUNT GAPBS_BFS_14_NODE_COUNT
#define GAPBS_EDGE_COUNT 53U
#define GAPBS_SOURCE 0
#define GAPBS_ALPHA 15
#define GAPBS_BETA 18

static const uint16_t out_offset[GAPBS_NODE_COUNT + 1] = {
    0, 12, 12, 17, 22, 23, 23, 23, 32, 41, 46, 47, 47, 48, 53};
static const uint8_t out_edge[GAPBS_EDGE_COUNT] = {
    1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13,
    1, 4, 6, 9, 10,
    2, 4, 9, 12, 13,
    6,
    1, 2, 3, 4, 9, 10, 11, 12, 13,
    1, 2, 3, 4, 7, 9, 11, 12, 13,
    1, 4, 6, 10, 11,
    1,
    1,
    2, 4, 9, 10, 11};

static const uint16_t in_offset[GAPBS_NODE_COUNT + 1] = {
    0, 0, 7, 12, 15, 22, 22, 26, 28, 29, 35, 40, 44, 48, 53};
static const uint8_t in_edge[GAPBS_EDGE_COUNT] = {
    0, 2, 7, 8, 9, 10, 12,
    0, 3, 7, 8, 13,
    0, 7, 8,
    0, 2, 3, 7, 8, 9, 13,
    0, 2, 4, 9,
    0, 8,
    0,
    0, 2, 3, 7, 8, 13,
    0, 2, 7, 9, 13,
    0, 7, 8, 9, 13,
    0, 3, 7, 8,
    0, 3, 7, 8};

static void clear_bits(uint8_t *bits)
{
    for (uint32_t node = 0; node < GAPBS_NODE_COUNT; node++) {
        bits[node] = 0;
    }
}

static void copy_bits(uint8_t *dst, const uint8_t *src)
{
    for (uint32_t node = 0; node < GAPBS_NODE_COUNT; node++) {
        dst[node] = src[node];
    }
}

static uint32_t count_out_edges(uint32_t node)
{
    return out_offset[node + 1] - out_offset[node];
}

static uint32_t bottom_up_step(const int32_t *parent,
                               const uint8_t *front_bits,
                               int32_t *next_parent,
                               uint8_t *next_bits,
                               uint32_t *next_frontier)
{
    uint32_t awake_count = 0;

    clear_bits(next_bits);
    for (uint32_t node = 0; node < GAPBS_NODE_COUNT; node++) {
        if (parent[node] >= 0) {
            continue;
        }
        for (uint16_t edge = in_offset[node]; edge < in_offset[node + 1];
             edge++) {
            uint32_t candidate = in_edge[edge];
            if (front_bits[candidate] != 0) {
                next_parent[node] = (int32_t)candidate;
                next_bits[node] = 1;
                next_frontier[awake_count++] = node;
                break;
            }
        }
    }
    return awake_count;
}

static uint32_t top_down_step(const int32_t *parent,
                              int32_t *next_parent,
                              const uint32_t *frontier,
                              uint32_t frontier_count,
                              uint32_t *next_frontier,
                              uint8_t *next_bits,
                              int64_t *scout_count)
{
    uint32_t next_count = 0;
    *scout_count = 0;
    clear_bits(next_bits);

    for (uint32_t index = 0; index < frontier_count; index++) {
        uint32_t node = frontier[index];
        for (uint16_t edge = out_offset[node]; edge < out_offset[node + 1];
             edge++) {
            uint32_t neighbour = out_edge[edge];
            if (parent[neighbour] < 0 && next_parent[neighbour] < 0) {
                next_parent[neighbour] = (int32_t)node;
                next_bits[neighbour] = 1;
                next_frontier[next_count++] = neighbour;
                *scout_count += count_out_edges(neighbour);
            }
        }
    }
    return next_count;
}

static uint32_t verify_result(const int32_t *parent)
{
    uint8_t reachable[GAPBS_NODE_COUNT] = {0};
    uint32_t queue[GAPBS_NODE_COUNT];
    uint32_t head = 0;
    uint32_t tail = 0;
    reachable[GAPBS_SOURCE] = 1;
    queue[tail++] = GAPBS_SOURCE;

    while (head < tail) {
        uint32_t node = queue[head++];
        for (uint16_t edge = out_offset[node]; edge < out_offset[node + 1];
             edge++) {
            uint32_t neighbour = out_edge[edge];
            if (reachable[neighbour] == 0) {
                reachable[neighbour] = 1;
                queue[tail++] = neighbour;
            }
        }
    }

    for (uint32_t node = 0; node < GAPBS_NODE_COUNT; node++) {
        if (reachable[node] == 0) {
            if (parent[node] != -1) {
                return 0;
            }
            continue;
        }
        if (node == GAPBS_SOURCE) {
            if (parent[node] != (int32_t)node) {
                return 0;
            }
            continue;
        }
        if (parent[node] < 0) {
            return 0;
        }
        uint32_t found = 0;
        uint32_t source = (uint32_t)parent[node];
        for (uint16_t edge = in_offset[node]; edge < in_offset[node + 1];
             edge++) {
            if (in_edge[edge] == source) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            return 0;
        }
    }
    return 1;
}

void gapbs_bfs_run_14(gapbs_bfs_result_t *result)
{
    int32_t parent[GAPBS_NODE_COUNT];
    uint32_t frontier[GAPBS_NODE_COUNT];
    uint32_t next_frontier[GAPBS_NODE_COUNT];
    uint8_t front_bits[GAPBS_NODE_COUNT];
    uint8_t next_bits[GAPBS_NODE_COUNT];
    uint32_t frontier_count = 1;
    int64_t edges_to_check = GAPBS_EDGE_COUNT;
    int64_t scout_count = count_out_edges(GAPBS_SOURCE);

    for (uint32_t node = 0; node < GAPBS_NODE_COUNT; node++) {
        parent[node] = -1;
    }
    parent[GAPBS_SOURCE] = GAPBS_SOURCE;
    frontier[0] = GAPBS_SOURCE;
    clear_bits(front_bits);
    front_bits[GAPBS_SOURCE] = 1;

    while (frontier_count != 0) {
        if (scout_count > edges_to_check / GAPBS_ALPHA) {
            uint32_t old_awake_count = frontier_count;
            uint32_t awake_count;
            do {
                awake_count = bottom_up_step(parent, front_bits, parent,
                                             next_bits, next_frontier);
                copy_bits(front_bits, next_bits);
                for (uint32_t i = 0; i < awake_count; i++) {
                    frontier[i] = next_frontier[i];
                }
                frontier_count = awake_count;
                if (awake_count < old_awake_count &&
                    awake_count <= GAPBS_NODE_COUNT / GAPBS_BETA) {
                    break;
                }
                old_awake_count = awake_count;
            } while (awake_count != 0);
            scout_count = 1;
        } else {
            edges_to_check -= scout_count;
            frontier_count = top_down_step(
                parent, parent, frontier, frontier_count, next_frontier,
                next_bits, &scout_count);
            for (uint32_t i = 0; i < frontier_count; i++) {
                frontier[i] = next_frontier[i];
            }
            copy_bits(front_bits, next_bits);
        }
    }

    result->node_count = GAPBS_BFS_14_NODE_COUNT;
    result->source = GAPBS_SOURCE;
    result->reached_nodes = 0;
    result->traversed_edges = 0;
    result->parent_checksum = 0;
    for (uint32_t node = 0; node < GAPBS_NODE_COUNT; node++) {
        if (parent[node] >= 0) {
            result->reached_nodes++;
            result->traversed_edges += count_out_edges(node);
            result->parent_checksum +=
                (uint64_t)(node + 1) * (uint64_t)(parent[node] + 1);
        }
    }
    result->verified = verify_result(parent);
}
#undef verify_result
#undef top_down_step
#undef bottom_up_step
#undef count_out_edges
#undef copy_bits
#undef clear_bits
#undef GAPBS_BETA
#undef GAPBS_ALPHA
#undef GAPBS_SOURCE
#undef GAPBS_EDGE_COUNT
#undef GAPBS_NODE_COUNT
#undef next_bits
#undef front_bits
#undef next_frontier
#undef frontier
#undef parent
#undef in_edge
#undef out_edge
#undef in_offset
#undef out_offset

/*
 * 内置图版本：每个节点有 16 条有向边，图在启动时建立双向 CSR 邻接表，
 * 节点 i 指向 (i+1) 到 (i+16) 的模 N 节点。四档规模共用这套图生成与 BFS
 * 逻辑，避免裸机环境依赖文件系统或把大数组压入栈。
 */
#define GAPBS_DEGREE 16U
#define GAPBS_SOURCE 0U
#define GAPBS_ALPHA 15U
#define GAPBS_BETA 18U

static uint32_t out_offset[GAPBS_BFS_4096_NODE_COUNT + 1U];
static uint32_t in_offset[GAPBS_BFS_4096_NODE_COUNT + 1U];
static uint16_t out_edge[GAPBS_BFS_4096_NODE_COUNT * GAPBS_DEGREE];
static uint16_t in_edge[GAPBS_BFS_4096_NODE_COUNT * GAPBS_DEGREE];
static int32_t parent[GAPBS_BFS_4096_NODE_COUNT];
static uint32_t frontier[GAPBS_BFS_4096_NODE_COUNT];
static uint32_t next_frontier[GAPBS_BFS_4096_NODE_COUNT];
static uint8_t front_bits[GAPBS_BFS_4096_NODE_COUNT];
static uint8_t next_bits[GAPBS_BFS_4096_NODE_COUNT];

static void build_graph(uint32_t node_count)
{
    for (uint32_t node = 0; node <= node_count; node++) {
        out_offset[node] = node * GAPBS_DEGREE;
        in_offset[node] = node * GAPBS_DEGREE;
    }

    for (uint32_t node = 0; node < node_count; node++) {
        for (uint32_t degree = 0; degree < GAPBS_DEGREE; degree++) {
            out_edge[out_offset[node] + degree] =
                (uint16_t)((node + degree + 1U) % node_count);
            in_edge[in_offset[node] + degree] =
                (uint16_t)((node + node_count - degree - 1U) % node_count);
        }
    }
}

static void clear_bits(uint8_t *bits, uint32_t node_count)
{
    for (uint32_t node = 0; node < node_count; node++) {
        bits[node] = 0;
    }
}

static void copy_bits(uint8_t *dst, const uint8_t *src, uint32_t node_count)
{
    for (uint32_t node = 0; node < node_count; node++) {
        dst[node] = src[node];
    }
}

static uint32_t bottom_up_step(const uint8_t *current_bits,
                               uint32_t node_count, uint32_t *next_count)
{
    *next_count = 0;
    clear_bits(next_bits, node_count);
    for (uint32_t node = 0; node < node_count; node++) {
        if (parent[node] >= 0) {
            continue;
        }
        for (uint32_t edge = in_offset[node]; edge < in_offset[node + 1];
             edge++) {
            uint32_t candidate = in_edge[edge];
            if (current_bits[candidate] != 0U) {
                parent[node] = (int32_t)candidate;
                next_bits[node] = 1;
                next_frontier[(*next_count)++] = node;
                break;
            }
        }
    }
    return *next_count;
}

static uint32_t top_down_step(uint32_t frontier_count, uint32_t node_count,
                              int64_t *scout_count)
{
    uint32_t next_count = 0;
    *scout_count = 0;
    clear_bits(next_bits, node_count);
    for (uint32_t index = 0; index < frontier_count; index++) {
        uint32_t node = frontier[index];
        for (uint32_t edge = out_offset[node]; edge < out_offset[node + 1];
             edge++) {
            uint32_t neighbour = out_edge[edge];
            if (parent[neighbour] < 0) {
                parent[neighbour] = (int32_t)node;
                next_bits[neighbour] = 1;
                next_frontier[next_count++] = neighbour;
                *scout_count += GAPBS_DEGREE;
            }
        }
    }
    return next_count;
}

static uint32_t verify_result(uint32_t node_count)
{
    if (parent[GAPBS_SOURCE] != (int32_t)GAPBS_SOURCE) {
        return 0;
    }
    for (uint32_t node = 1; node < node_count; node++) {
        if (parent[node] < 0 || (uint32_t)parent[node] >= node_count) {
            return 0;
        }
        uint32_t parent_node = (uint32_t)parent[node];
        uint32_t delta = (node + node_count - parent_node) % node_count;
        if (delta == 0U || delta > GAPBS_DEGREE) {
            return 0;
        }
    }
    return 1;
}

static void gapbs_bfs_run_size(gapbs_bfs_result_t *result,
                               uint32_t node_count)
{
    uint32_t frontier_count = 1;
    int64_t edges_to_check = (int64_t)node_count * GAPBS_DEGREE;
    int64_t scout_count = GAPBS_DEGREE;

    build_graph(node_count);
    for (uint32_t node = 0; node < node_count; node++) {
        parent[node] = -1;
    }
    parent[GAPBS_SOURCE] = GAPBS_SOURCE;
    frontier[0] = GAPBS_SOURCE;
    clear_bits(front_bits, node_count);
    front_bits[GAPBS_SOURCE] = 1;

    while (frontier_count != 0U) {
        if (scout_count > edges_to_check / GAPBS_ALPHA) {
            uint32_t old_count = frontier_count;
            do {
                bottom_up_step(front_bits, node_count, &frontier_count);
                copy_bits(front_bits, next_bits, node_count);
                for (uint32_t index = 0; index < frontier_count; index++) {
                    frontier[index] = next_frontier[index];
                }
                if (frontier_count < old_count &&
                    frontier_count <= node_count / GAPBS_BETA) {
                    break;
                }
                old_count = frontier_count;
            } while (frontier_count != 0U);
            scout_count = 1;
        } else {
            edges_to_check -= scout_count;
            frontier_count =
                top_down_step(frontier_count, node_count, &scout_count);
            for (uint32_t index = 0; index < frontier_count; index++) {
                frontier[index] = next_frontier[index];
            }
            copy_bits(front_bits, next_bits, node_count);
        }
    }

    result->node_count = node_count;
    result->source = GAPBS_SOURCE;
    result->reached_nodes = 0;
    result->traversed_edges = 0;
    result->parent_checksum = 0;
    for (uint32_t node = 0; node < node_count; node++) {
        if (parent[node] >= 0) {
            result->reached_nodes++;
            result->traversed_edges += GAPBS_DEGREE;
            result->parent_checksum +=
                (uint64_t)(node + 1U) * (uint64_t)(parent[node] + 1);
        }
    }
    result->verified = verify_result(node_count);
}

void gapbs_bfs_run_512(gapbs_bfs_result_t *result)
{
    gapbs_bfs_run_size(result, GAPBS_BFS_512_NODE_COUNT);
}

void gapbs_bfs_run_1024(gapbs_bfs_result_t *result)
{
    gapbs_bfs_run_size(result, GAPBS_BFS_1024_NODE_COUNT);
}

void gapbs_bfs_run_2048(gapbs_bfs_result_t *result)
{
    gapbs_bfs_run_size(result, GAPBS_BFS_2048_NODE_COUNT);
}

void gapbs_bfs_run_4096(gapbs_bfs_result_t *result)
{
    gapbs_bfs_run_size(result, GAPBS_BFS_4096_NODE_COUNT);
}
