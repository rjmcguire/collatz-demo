#include<stdio.h>
#include "collatz.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	int n;

	if (argc != 2) {
		printf("Usage: %s [int]\n", argv[0]);
		return 1;
	}

	n = atoi(argv[1]);
	collatz(n);
  return 0;
}
