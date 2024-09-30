#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cache.h"
#include "collatz.h"

// Runs when called through the h file
int Collatz_Conjecture(int Random_Number) {
    // Initializes Counter to prevent adding counts
    // together rather than individually
    int Step_Counter = 0;
    // Loops while the Random_Number isn't 1
    while (Random_Number != 1) {
            // If it's even we proceed with dividing by 2
            if ((Random_Number % 2) == 0) {
                Random_Number = Random_Number / 2;
                Step_Counter += 1;
            // If it's odd we proceed with multiplying by 3 and adding 1
            } else if ((Random_Number % 2) == 1) {
                Random_Number = (Random_Number * 3) + 1;
                Step_Counter += 1;
            }
        }
    // Return our counter once the Random_Number is 1
    return Step_Counter;
}

// Our line arguments are inserted onto our main
// Stores each of the corresponding arguments to their respective variables.
int main(int argc, char* argv[]) {
    int Num_Of_Tests = atoi(argv[1]);
    int Smallest_Value = atoi(argv[2]);
    int Largest_Value = atoi(argv[3]);
    //char *policy = argv[4]; 
    //int Cache_Size = atoi(argv[5]);

    // Runs the Caclulations of collatz conjecture with the given Num_of_Tests
    for (int ix = 0; ix < Num_Of_Tests; ix++) {
        // This gives our resulting random number
        // Within the range from Smallest_Value and Largest_Value
        int Random_Number = rand() % 
                (Largest_Value - Smallest_Value + 1) + Smallest_Value;

        // Prints our number received from Random_Number
        printf("Random Number: %d\n", Random_Number);

        // Run over Collatz_Conjecture calling it from h and using our value
        int Step_Counter = Collatz_Conjecture(Random_Number);

        // Once Calculated returns to print out the Total Steps it took
        printf("Total Steps: %d\n", Step_Counter);
    }

    return 0;
}