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
	struct CacheEntry *cache;
	int cacheIndex = 0;
	struct CacheEntry newEntry;

	if (argc != 2) {
		printf("Usage: %s [int]\n", argv[0]);
		return 1;
	}


	cache = calloc(MAX_CACHE, sizeof(struct CacheEntry));
	for (int i=0; i<MAX_CACHE; i++) {
		cache[i].number = 0;
		cache[i].length = 0;
	}

	n = atoi(argv[1]);

	for (int i=n; i>=1; --i) {
		tmp = collatz(i, cache);
		if (tmp > longestChain) {
			result = i;
			longestChain = tmp;
		}
		newEntry.number = i;
		newEntry.length = tmp;
		cache[cacheIndex++] = newEntry;
		if (cacheIndex > MAX_CACHE) {
			cacheIndex = 0;
		}
	}
	printf("result %d, count %lld\n", result, longestChain);

	free(cache);

	return 0;
}
