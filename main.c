#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "collatz.h"
#include "cache.h"

int main(int argc, char **argv) {
	int n;
	int64_t tmp = 0;
	int64_t longestChain = 0;
	int result = 0;
	int *cache_keys;
	int *cache_values;
	int cacheIndex = 0;

	if (argc != 2) {
		printf("Usage: %s [int]\n", argv[0]);
		return 1;
	}


	cache_keys   = calloc(MAX_CACHE, sizeof(int));
	cache_values = calloc(MAX_CACHE, sizeof(int));
	for (int i=0; i<MAX_CACHE; i++) {
		cache_keys[i] = 0;
	}

	n = atoi(argv[1]);

	for (int i=n; i>=1; --i) {
		tmp = collatz(i, cache_keys, cache_values);
		if (tmp > longestChain) {
			result = i;
			longestChain = tmp;
		}
		cache_values[cacheIndex] = tmp;
		cache_keys[cacheIndex] = i;
		++cacheIndex;

		if (cacheIndex > MAX_CACHE) {
			cacheIndex = 0;
		}
	}
	printf("result %d, count %lld\n", result, longestChain);

	free(cache_keys);
	free(cache_values);

	return 0;
}
