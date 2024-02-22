// CS2211b 2023
// Assignment 5
// Teagan Martins
// 251234624
// tmart25
// April 5, 2023

#ifndef BSTREE_H
#define BSTREE_H

#include "datatype.h"

// Defining BStree_node
typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;

typedef BStree_node** BStree;

// Function prototypes for BStree operations
BStree bstree_ini(void); // Initialize binary search tree
void bstree_insert(BStree bst, Key key, Data data); // Insert node into binary search tree
Data bstree_search(BStree bst, Key key); // Search binary search tree
void bstree_traverse(BStree bst); // In-order traversal of binary search tree
void bstree_free(BStree bst); // Free dynamically allocated memory

#endif // BSTREE_H

