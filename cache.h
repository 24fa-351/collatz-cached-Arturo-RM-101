#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool cache_has(int key);
int cache_get(int key);
void cache_put(int key, int value);
int actual_cache_hits();
int actual_cache_tests();

#endif
