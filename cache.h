#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include <stdlib.h>

// We create some type defining structs below
// These set of variables in the struct will be used
// for the intialization of our cache
typedef struct {
    int Key;
    int Value;
    int Uses;
} Cache_Entry;

// These sets of variables for this struct will focus
// on the actual cachinh
typedef struct {
    Cache_Entry *Tests;
    int Max_Capacity;
    int Entries;
}Cache;

// The function definitions of the cache.h which are used
// When called
Cache *Allocate_Cache(int Max_Capacity);
int Get_Steps();
int Hit_Rate();
int Cache_Storage();

#endif