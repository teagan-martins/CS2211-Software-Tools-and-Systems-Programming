// CS2211b 2023
// Assignment 5
// Teagan Martins
// 251234624
// tmart25
// April 5, 2023

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

// Create binary search node
BStree_node *new_node(Key key, Data data) {
    BStree_node *node = (BStree_node *) malloc(sizeof(BStree_node)); // Allocate memory
    node->key = key; // Set key
    node->data = data; // Set data
    node->left = NULL; // Set left child to null
    node->right = NULL; // Set right child to null
    return node; // Return new node
}

// Initialize binary search tree
BStree bstree_ini(void) {
    BStree bst = (BStree) malloc(sizeof(BStree_node *)); // Allocate memory
    *bst = NULL; // Set pointer to null
    return bst; // Return pointer
}

// Insert node into binary search tree
void bstree_insert(BStree bst, Key key, Data data) {
    if (*bst == NULL) { // If binary search tree is empty...
        *bst = new_node(key, data); // Create new node as root
    } else { // Otherwise...
        int compare = key_comp(key, (*bst)->key); // Compare key with current key
        if (compare < 0) { // If key is smaller than current key...
            bstree_insert(&((*bst)->left), key, data); // Insert as left key
        } else if (compare > 0) { // If key is larger than current key...
            bstree_insert(&((*bst)->right), key, data); // Insert as right key
        }
    }
}

// Search binary search tree
Data bstree_search(BStree bst, Key key) {
    if (*bst == NULL) { // If tree is empty...
        return NULL; // Return NULL
    }

    int compare = key_comp(key, (*bst)->key); // Compare key with current key
    if (compare < 0) { // If key is smaller than current key...
        return bstree_search(&((*bst)->left), key); // Recursively search left tree
    } else if (compare > 0) { // If key is larger than current key...
        return bstree_search(&((*bst)->right), key); // Recursively search right tree
    } else { // Otherwise...
        return (*bst)->data; // Return current key
    }
}

// In-order traversal of binary search tree
void bstree_traverse(BStree bst) {
    if (*bst == NULL) { // If binary search tree is empty...
        return; // Do nothing (return)
    }

    bstree_traverse(&((*bst)->left)); // Traverse left tree
    key_print((*bst)->key); // Print current key
    printf("\t"); // Tab (indent)
    data_print((*bst)->data); 
    printf("\n"); // Newline
    bstree_traverse(&((*bst)->right)); // Traverse right tree
}

// Free dynamically allocated memory
void bstree_free(BStree bst) {
    if (*bst == NULL) { // If binary search tree is empty...
        return; // Do nothing (return)
    }

    bstree_free(&((*bst)->left)); // Recursively free left tree
    bstree_free(&((*bst)->right)); // Recursively free right tree
    key_free((*bst)->key); // Free current key
    data_free((*bst)->data); // Free current data
    free(*bst); // Free current node
}
