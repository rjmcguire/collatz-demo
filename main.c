#include <stdio.h>
#include "collatz.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	uint64_t n;
	uint64_t tmp;
	uint64_t longestChain;
	uint64_t result;

	if (argc != 2) {
		printf("Usage: %s [int]\n", argv[0]);
		return 1;
	}

	n = atoi(argv[1]);
	result = 0;
	for (uint64_t i=n; i>=1; --i) {
		tmp = collatz(i);
		if (tmp > longestChain) {
			result = i;
			longestChain = tmp;
		}
	}
	printf("result %lld, count %lld\n", result, longestChain);
  return 0;
}
