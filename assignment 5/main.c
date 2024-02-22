// CS2211b 2023
// Assignment 5
// Teagan Martins
// 251234624
// tmart25
// April 5, 2023

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {	
    Matrix m = matrix_construction(); // Create matrix
    Index index1 = (Index) malloc(100 * sizeof(char)); // Allocate memory for first string
    Index index2 = (Index) malloc(100 * sizeof(char)); // Allocate memory for second string

    while (scanf("%99s %99s", index1, index2) == 2) { // While reading 2 strings per line...
        if (matrix_index_in(m, index1, index2)) { // If the indices are in the matrix already...
            Value value_current = matrix_get(m, index1, index2); // Increment current value
            matrix_set(m, index1, index2, value_current + 1); // Set matrix with current value + 1
        } else { // Otherwise...
            matrix_set(m, index1, index2, 1); // Set matrix with 1
        }
    }

    matrix_list(m); // Print or format matrix display
    matrix_destruction(m); // Free matrix memory

    free(index1); // Free memory for first string
    free(index2); // Free memory for second string

    return 0; // Return 0
}

