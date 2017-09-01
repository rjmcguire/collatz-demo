#ifndef CACHE_H
#define CACHE_H 1

#define MAX_THREADS 4

#define MAX_CACHE 1024 * 1024

struct CacheEntry {
	uint64_t number;
	uint64_t length;
};

#endif