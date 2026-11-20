#include "report.h"

#include <inttypes.h>
#include <stdio.h>
#include "../hw/ghe.h"

volatile uint32_t hart_traffic_ready[NUM_HARTS];

int report_end(uint64_t start_cpu, uint64_t end_cpu, uint64_t hart_id)
{
    /* This is software completion, not a package-result or cache drain. */
    while (hart_traffic_ready[1] == 0 || hart_traffic_ready[2] == 0 ||
           hart_traffic_ready[3] == 0 || hart_traffic_ready[4] == 0) {
    }
    __sync_synchronize();
    ghe_common_observer_stop();
    printf("[ROI] hart=%" PRIu64 " start=%" PRIu64 " stop=%" PRIu64
           " cycles=%" PRIu64 "\n", hart_id, start_cpu, end_cpu,
           end_cpu - start_cpu);
    printf("[COMPLETION] checker_software_ready=4 cache_drain=UNRESOLVED\n");
    return hart_id == 0 && end_cpu > start_cpu;
}
