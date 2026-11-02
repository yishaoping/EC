#ifndef GAPBS_BFS_H
#define GAPBS_BFS_H

#include <stdint.h>

/* GAPBS BFS 结果，供 test.c 在收尾阶段输出并检查。 */
typedef struct {
    uint32_t node_count;
    uint32_t source;
    uint32_t reached_nodes;
    uint32_t traversed_edges;
    uint64_t parent_checksum;
    uint32_t verified;
} gapbs_bfs_result_t;

/* 可用的内置 GAPBS 图规模；每个节点固定 16 条有向边（14 节点图除外）。 */
#define GAPBS_BFS_14_NODE_COUNT 14U
#define GAPBS_BFS_512_NODE_COUNT 512U
#define GAPBS_BFS_1024_NODE_COUNT 1024U
#define GAPBS_BFS_2048_NODE_COUNT 2048U
#define GAPBS_BFS_4096_NODE_COUNT 4096U

/* [BENCHMARK SIZE] 可在 test.c 调用点切换到这些明确的节点规模。 */
void gapbs_bfs_run_14(gapbs_bfs_result_t *result);

/* 执行 512 节点的方向优化 BFS。 */
void gapbs_bfs_run_512(gapbs_bfs_result_t *result);

/* 执行 1024 节点的方向优化 BFS。 */
void gapbs_bfs_run_1024(gapbs_bfs_result_t *result);

/* 执行 2048 节点的方向优化 BFS。 */
void gapbs_bfs_run_2048(gapbs_bfs_result_t *result);

/* 执行 4096 节点的方向优化 BFS。 */
void gapbs_bfs_run_4096(gapbs_bfs_result_t *result);

#endif
