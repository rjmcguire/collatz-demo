#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// int cache[1*1024*1024*1024];


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

uint64_t collatz(uint64_t n) {
	uint64_t num = n;
	uint64_t count;
	for (count=0; n>1; ++count) {
		// if (cache[n] != 0) {
		// 	// printf("hit\n");
		// 	return count + cache[n];
		// }
		n = step(n);

		// printf("%d\n", n);
	}
	// printf("cache %d\n", num);
	// cache[num] = count;
	return count;
}
