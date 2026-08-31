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

/* 在固定 512 节点、8192 边中图上执行一次方向优化 BFS。 */
void gapbs_bfs_run(gapbs_bfs_result_t *result);

#endif
