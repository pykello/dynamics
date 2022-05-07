   // Flawed sample mystery program to measure how long an add takes.
   // dick sites 2016.06.25

   #include <stdint.h>
   #include <stdio.h>
   #include <time.h>
//   #include <x86intrin.h>
   #include "now.h" 

   static const int kIterations = 1000 * 1000000;

   int main (int argc, const char** argv) {
     uint64_t startcy, stopcy;
     uint64_t sum = 0;

     startcy = Now();                       // starting cycle count
     for (int i = 0; i < kIterations; ++i) {   // loop kIterations times
       sum += 1;                               // the add we want to measure
     }
     stopcy = Now();                       // ending cycle count

     int64_t elapsed = stopcy - startcy;
     double felapsed = elapsed;
     fprintf(stdout, "%d iterations, %lu cycles, %4.2f cycles/iteration\n",
             kIterations, elapsed, felapsed / kIterations);
     return 0;
   }
