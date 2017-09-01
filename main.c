#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#include "collatz.h"
#include "cache.h"

struct CacheEntry main1(uint64_t start, uint64_t end);
void* thread_main(void *arg);

struct WorkEntry {
	uint64_t upper;
	uint64_t lower;
	struct CacheEntry result;
};

int main(int argc, char **argv) {
	uint64_t n;
	uint64_t work_set_size;

	if (argc != 2) {
		printf("Usage: %s [int]\n", argv[0]);
		return 1;
	}

	n = atoi(argv[1]);

	work_set_size = ceil(n / (double)MAX_THREADS);
	// split the numbers into sets then
	// run the numbers through a set of workers
	struct WorkEntry results[MAX_THREADS];
	pthread_t workers[MAX_THREADS];
	for (int i=0; i<MAX_THREADS; i++) {
		results[i].lower = (work_set_size * i)+1;
		results[i].upper   = (work_set_size * (i+1));
		// printf("%lld vs %lld\n", results[i].upper, n);
		if (results[i].upper > n) {
			results[i].upper = n;
		}
		// printf("work upper:%lld lower:%lld\n", results[i].upper, results[i].lower);

		// results[i] = main1(upper, lower);
		if(pthread_create(&workers[i], NULL, thread_main, &results[i])) {
			fprintf(stderr, "Error creating thread\n");
			return 1;
		}
	}
	for (int i=0; i<MAX_THREADS; i++) {
		pthread_join(workers[i], NULL);
	}

	struct CacheEntry result = { .number=0, .length=0};
	for (int i=0; i<MAX_THREADS; i++) {
		if (result.length < results[i].result.length) {
			result = results[i].result;
		}
	}
	printf("result: number:%lld length:%lld\n", result.number, result.length);
}

void* thread_main(void *arg) {
	struct WorkEntry* work;
	work = arg;
	work->result = main1(work->upper, work->lower);

	return NULL;
}

struct CacheEntry main1(uint64_t start, uint64_t end) {
	int64_t tmp = 0;
	int64_t longestChain = 0;
	uint64_t result = 0;
	struct CacheEntry *cache;
	uint64_t cacheIndex = 0;
	struct CacheEntry newEntry;


	cache = calloc(MAX_CACHE, sizeof(struct CacheEntry));
	for (int i=0; i<MAX_CACHE; i++) {
		cache[i].number = 0;
		cache[i].length = 0;
	}

	for (uint64_t i=start; i>=end; --i) {
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
	// printf("result %lld, count %lld\n", result, longestChain);

	free(cache);

	newEntry.number = result;
	newEntry.length = longestChain;
	return newEntry;
}
