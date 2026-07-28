/* MEEK-integrated main for Embench benchmarks

   Wraps the standard Embench flow with MEEK rStartup/rCleanup so that
   all instructions executed by the benchmark are checked by the 4 checker
   Rocket cores.

   Build: use build_meek.sh
*/

#include "support.h"
#include "meek.h"

int __attribute__((used))
main(int argc __attribute__((unused)),
     char *argv[] __attribute__((unused)))
{
  volatile int result;
  int correct;

  initialise_board();
  initialise_benchmark();
  warm_caches(WARMUP_HEAT);

  // ---- MEEK start ----
  rStartup();

  start_trigger();
  result = benchmark();
  stop_trigger();

  rCleanup();
  // ---- MEEK end ----

  correct = verify_benchmark(result);
  return (!correct);
}
