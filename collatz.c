#include <stdint.h>
#include <stdio.h>


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
	if ((n & 1) == 1) {
		return odd(n);
	}
	return even(n);
}

int32_t collatz(int32_t n) {
	while (n>1) {
		n = step(n);
		printf("%d\n", n);
	}
	return n;
}
