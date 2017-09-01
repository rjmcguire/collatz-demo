#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "cache.h"

uint64_t even(uint64_t n) {
	// printf("even %d\n", n);
	// n / 2
	return n / 2;
}

uint64_t odd(uint64_t n) {
	// printf("odd %d\n", n);
	// 3n + 1
	return (n * 3) + 1;
}

uint64_t step(uint64_t n) {
	if (n > ((INT64_MAX-1) / 3)) {
		fprintf(stderr, "integer overflow at %lld\n", n);
		exit(2);
	}
	if ((n & 1) == 1) {
		return odd(n);
	}
	return even(n);
}

uint64_t collatz(uint64_t n, struct CacheEntry cache[]) {
	int64_t count;
	for (count=0; n>1; ++count) {
		for (int i=0; i<MAX_CACHE; i++) {
			if (cache[i].number == 0) {
				break;
			}
			if (cache[i].number == n) {
				// printf("cache entry, number:%d length:%d\n", cache[i].number, cache[i].length);
				return count + cache[i].length;
			}
		}
		n = step(n);
		// printf("%d\n", n);
	}
	return count;
}
