#ifndef GAPBS_BFS_H
#define GAPBS_BFS_H

#include <stdint.h>

/* GAPBS BFS 结果，供 test.c 在收尾阶段输出并检查。 */
typedef struct {
    uint32_t source;
    uint32_t reached_nodes;
    uint32_t traversed_edges;
    uint64_t parent_checksum;
    uint32_t verified;
} gapbs_bfs_result_t;

/* 执行 GAPBS 的最小 14 节点、53 边回归图。 */
void gapbs_bfs_run_min(gapbs_bfs_result_t *result);

/* 裸机可用的内置 GAPBS 图规模；每个节点固定 16 条有向边。 */
#define GAPBS_BFS_512_NODE_COUNT 512U
#define GAPBS_BFS_1024_NODE_COUNT 1024U
#define GAPBS_BFS_2048_NODE_COUNT 2048U
#define GAPBS_BFS_4096_NODE_COUNT 4096U

/* 保留原有命名，避免已有调用方失效。 */
#define GAPBS_BFS_MEDIUM_NODE_COUNT GAPBS_BFS_512_NODE_COUNT
#define GAPBS_BFS_MAX_NODE_COUNT GAPBS_BFS_4096_NODE_COUNT

/* 执行 512 节点的方向优化 BFS。 */
void gapbs_bfs_run_512(gapbs_bfs_result_t *result);

/* 执行 1024 节点的方向优化 BFS。 */
void gapbs_bfs_run_1024(gapbs_bfs_result_t *result);

/* 执行 2048 节点的方向优化 BFS。 */
void gapbs_bfs_run_2048(gapbs_bfs_result_t *result);

/* 执行 4096 节点的方向优化 BFS。 */
void gapbs_bfs_run_4096(gapbs_bfs_result_t *result);

/* 兼容旧接口：分别对应 512 和 4096 节点。 */
void gapbs_bfs_run(gapbs_bfs_result_t *result);
void gapbs_bfs_run_max(gapbs_bfs_result_t *result);

#endif
