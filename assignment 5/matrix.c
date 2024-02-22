// CS2211b 2023
// Assignment 5
// Teagan Martins
// 251234624
// tmart25
// April 5, 2023

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Create a new matrix
Matrix matrix_construction(void) {
    return bstree_ini(); // Initialize matrix
}

// Check if location is in matrix
unsigned char matrix_index_in(Matrix m, Index index1, Index index2) {
    Key key = key_ini(); // Create a new key
    key_set(key, index1, index2); // Set a key
    Data data = bstree_search(m, key); // Search for the key in the matrix
    key_free(key); // Free memory taken by key
    return data != NULL; // Return whether data is NULL or not
}

// Return value at location in matrix
Value matrix_get(Matrix m, Index index1, Index index2) {
    Key key = key_ini(); // Create a new key
    key_set(key, index1, index2); // Set a key
    Data data = bstree_search(m, key); // Search for the key in the matrix
    key_free(key); // Free memory taken by key

    if (data == NULL) { // If data is null...
        fprintf(stderr, "Error: matrix index not found\n"); // Print that the matrix index was not found
        return -1; // Return -1
    } // Otherwise...
    return *data; // Return value
}

// Assign value at location in matrix
void matrix_set(Matrix m, Index index1, Index index2, Value value) {
    Key key = key_ini(); // Create a new key
    key_set(key, index1, index2); // Set a key
    Data data = bstree_search(m, key); // Search for the newly created key

    if (data == NULL) { // If the data is null...
        Data new_data = data_ini(); // Initialize new data
        data_set(new_data, value); // Set data
        bstree_insert(m, key, new_data); // Insert the new data into the matrix
    } else { // Otherwise...
        data_set(data, value); // Set data
        key_free(key); // Free key memory
    }
}

// Format the output
void matrix_list(Matrix m) {
    printf("%-10s %-10s %-10s\n", "String 1", "String 2", "Occurrence");
    bstree_traverse(m); // Print matrix
}

// Free memory
void matrix_destruction(Matrix m) {
    bstree_free(m); // Free memory
    free(m); // Free memory
}

