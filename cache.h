#ifndef CACHE_H
#define CACHE_H 1

#define MAX_CACHE 1024 * 1024

struct CacheEntry {
	int number;
	int length;
};

#endif