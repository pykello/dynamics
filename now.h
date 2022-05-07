
inline int64_t Now() {
#if defined(__x86_64__) || defined(__amd64__)
	printf("a\n");
	uint64_t low, high;
	__asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
	return (high << 32) | low;
#elif defined(__ARM_ARCH)
	printf("b\n");
	uint32_t pmccntr;
 	uint32_t pmuseren;
	uint32_t pmcntenset;
	// Read the user mode perf monitor counter access permissions.
	asm volatile("mrc p15, 0, %0, c9, c14, 0" : "=r"(pmuseren));
	if (pmuseren & 1) {  // Allows reading perfmon counters for user mode code.
	    printf("c\n");
	    asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r"(pmcntenset));
	    if (pmcntenset & 0x80000000ul) {  // Is it counting?
	      printf("d\n");
	      asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r"(pmccntr));
	      // The counter is set up to count every 64th cycle
	      return static_cast<int64_t>(pmccntr) * 64;  // Should optimize to << 6
	    }
	}
#endif
	printf("e\n");
	return -1;
}
