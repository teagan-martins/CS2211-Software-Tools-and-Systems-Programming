// CS2211b 2023
// Assignment 5
// Teagan Martins
// 251234624
// tmart25
// April 5, 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

// Create a new key
Key key_ini() {
    return (Key) malloc(sizeof(Key_struct)); // Return key with allocated memory
}

// Copy strings
void key_set(Key key, char *str1, char *str2) {
    key->str1 = string_dup(str1); // Copy strings and set in key
    key->str2 = string_dup(str2);
}

// Compare two keys
int key_comp(Key key1, Key key2) {
    int compare = strcmp(key1->str1, key2->str1); // Compare the first string of the keys
    if (compare != 0) { // If the strings are not the same...
        return compare; // Return compare
    } // Otherwise, if compare is 0...
    return strcmp(key1->str2, key2->str2); // Return the comparison of the second strings
}

// Print a key
void key_print(Key key) {
    printf("%-10s %-10s", key->str1, key->str2); // Print string 1 and string 2
}

// Free memory
void key_free(Key key) {
    free(key->str1); // Free memory for string 1
    free(key->str2); // Free memory for string 2
    free(key); // Free memory for key
}

// Duplicate string
char * string_dup(char *str) {
    char *new_str = (char *) malloc(strlen(str) + 1); // Allocate memory
    strcpy(new_str, str); // Copy string
    return new_str; // Return new string
}

// Initialize data
Data data_ini() {
    return (Data) malloc(sizeof(int));
}

// Set data
void data_set(Data data, int intdata) {
    *data = intdata; // Assign value of data with intdata
}

// Print data
void data_print(Data data) {
    printf("%-10d", *data); // Print data
}

// Free memory for data
void data_free(Data data) {
    free(data); // Free memory for data
}
