#include <stdio.h>
#include <stdlib.h>

#include "cache.h"
#define LRU
//#define FIFO
//#define RANDOM

#define MAX_CACHE_SIZE 1000
int number_of_cache_hits = 0;
int number_of_cache_requests = 0;

// Sturct to store key, value, and uses for cache entry
typedef struct {
    int Key;
    int Value;
    int Uses;
    int last_used;
    int when_inserted;
} Cache_Entry;

// Cache array using struct to store data
Cache_Entry cache[MAX_CACHE_SIZE + 1];

int number_of_cache_entries = 0;

// Rewrite cache_had, cache_get, and cache_put to use the cache array

// Checks to see if the number is already in the cache array
// Returning a boolean value instead of the value
bool cache_has(int key) {
    number_of_cache_requests++;
    for (int ix = 1; ix <= number_of_cache_entries; ix++) {
        if (cache[ix].Key == key) {
            number_of_cache_hits++;
            return true;
        }
    }
    return false;
}

// Grabs the value from the cache array from a given key
// If not present it returns 0
int cache_get(int key) {
    for (int ix = 1; ix <= number_of_cache_entries; ix++) {
        if (cache[ix].Key == key) {
            cache[ix].Uses++;
            cache[ix].last_used = number_of_cache_requests;
            return cache[ix].Value;
        }
    }
    return 0;
}

int cache_find_empty_location() {
    if (number_of_cache_entries < MAX_CACHE_SIZE) {
        printf("Cache not empty, returning %d\n", number_of_cache_entries);
        return number_of_cache_entries++;
    }
    #ifdef LRU
    int oldest_cache_index_so_far = 1;
    for (int cache_index = 2; cache_index <= number_of_cache_entries; cache_index++) {
        if (cache[cache_index].Uses == 0) {
            printf("Found an unused entry at index %d\n", cache_index);
            return cache_index;
        }
        if (cache[cache_index].last_used < cache[oldest_cache_index_so_far].last_used) {
            // Oldest entry we have found so far
            // We change it if it's newer in the current entry
            // If first entry in cache is used number is 10, and go look at next entry and it was used in 5
            oldest_cache_index_so_far = cache_index;
        }
    }
    printf("Returning oldest entry at index %d\n", oldest_cache_index_so_far);
    return oldest_cache_index_so_far;
    #endif
    #ifdef RANDOM
    #endif
    #ifdef FIFO
    #endif
}


// Utilizes the cache array to store the key and value if not present
// In the cache array already
void cache_put(int key, int value) {
    int new_entry_index = cache_find_empty_location();
    cache[new_entry_index].Key = key;
    cache[new_entry_index].Value = value;
    cache[new_entry_index].Uses = 0;
    cache[new_entry_index].last_used = 0;
    cache[new_entry_index].when_inserted = number_of_cache_requests;
}

// Throughout the tests it will run this to see if the number is already
// In the cache and if so it adds a hit to number_of_cache_hits
int actual_cache_hits() { return number_of_cache_hits; }

// Works to return the number of cache requests don't that weren't
// Already in the cache?
int actual_cache_tests() { return number_of_cache_requests; }
