// https://github.com/google/benchmark/blob/v1.1.0/src/cycleclock.h#L116
inline int64_t Now() {
#if defined(__x86_64__) || defined(__amd64__)
	uint64_t low, high;
	__asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
	return (high << 32) | low;
#elif defined(__ARM_ARCH)
	uint32_t cc = 0;
	__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (cc));
	return cc;
#endif
	return -1;
}

