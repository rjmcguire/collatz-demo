#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int32_t even(int32_t n) {
	// printf("even %d\n", n);
	// n / 2
	return n / 2;
}

int32_t odd(int32_t n) {
	// printf("odd %d\n", n);
	// 3n + 1
	return (n * 3) + 1;
}

int32_t step(int32_t n) {
	if (n > ((INT_MAX-1) / 3)) {
		fprintf(stderr, "integer overflow at %d\n", n);
		exit(2);
	}
	if ((n & 1) == 1) {
		return odd(n);
	}
	return even(n);
}

int32_t collatz(int32_t n) {
	int64_t count;
	for (count=0; n>1; ++count) {
		n = step(n);
		// printf("%d\n", n);
	}
	return count;
}
