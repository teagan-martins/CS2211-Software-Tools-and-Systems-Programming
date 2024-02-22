// CS2211b 2023
// Assignment 5
// Teagan Martins
// 251234624
// tmart25
// April 5, 2023

#ifndef MATRIX_H
#define MATRIX_H

#include "bstree.h"

typedef BStree Matrix;
typedef char* Index;
typedef int Value;

// Function prototypes for Matrix operations
Matrix matrix_construction(void); // Create matrix
unsigned char matrix_index_in(Matrix m, Index index1, Index index2); // Check for location in matrix
Value matrix_get(Matrix m, Index index1, Index index2); // Check for value in matrix
void matrix_set(Matrix m, Index index1, Index index2, Value value); // Set matrix value
void matrix_list(Matrix m); // Format matrix display
void matrix_destruction(Matrix m); // Free memory

#endif // MATRIX_H

