#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cache.h"

bool is_even(int number) {
    return (number % 2) == 0;
}

// Returns the number of steps it takes to reach 1
// test_number has to be greater or equal to 1
unsigned int collatz_conjecture(unsigned int test_number) {
    unsigned int original_test_number = test_number;

    if (cache_has(test_number)) {
        return cache_get(test_number);
    }

    unsigned int step_counter = 0;
    while (test_number != 1) {
        if (is_even(test_number)) {
            test_number = test_number / 2;
        } else {
            test_number = (test_number * 3) + 1;
        }
        step_counter += 1;
    }

    cache_put(original_test_number, step_counter);

    return step_counter;
}

int random_number_between(int smallest, int biggest) {
    return rand() % (biggest - smallest + 1) + smallest;
}

int main(int argc, char* argv[]) {

    if (argc != 4) {
        printf("Usage: %s <Num_of_Tests> <Smallest_Value> <Largest_Value>\n", argv[0]);
        return 1;
    }

    unsigned int number_of_tests = atoi(argv[1]);
    unsigned int smallest_value = atoi(argv[2]);
    unsigned int largest_value = atoi(argv[3]);

    for (int ix = 0; ix < number_of_tests; ix++) {
        unsigned int random_number = random_number_between(smallest_value, largest_value);

        unsigned int step_counter = collatz_conjecture(random_number);

        printf("%u Steps, %u Number\n", step_counter, random_number);
    }

    unsigned int cache_hits = actual_cache_hits();
    unsigned int cache_tests = actual_cache_tests();
    
    // Prevent this to divide by zero when calculating hit rate
    if (cache_tests == 0) {
        cache_tests = 1;
    }

    double hit_rate = (double)cache_hits / cache_tests;

    printf("The hit rate over number of %u tests is: %f\n", cache_tests, hit_rate);

    return 0;
}
