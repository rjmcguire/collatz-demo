#include <stdio.h>
#include "collatz.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	int n;
	int64_t tmp;
	int64_t longestChain;
	int result;

	if (argc != 2) {
		printf("Usage: %s [int]\n", argv[0]);
		return 1;
	}

	n = atoi(argv[1]);
	result = 0;
	for (int i=n; i>=1; --i) {
		tmp = collatz(i);
		if (tmp > longestChain) {
			result = i;
			longestChain = tmp;
		}
	}
	printf("result %d, count %lld\n", result, longestChain);
  return 0;
}
