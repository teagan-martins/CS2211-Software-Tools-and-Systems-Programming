// CS2211b 2023
// Assignment 5
// Teagan Martins
// 251234624
// tmart25
// April 5, 2023

#ifndef DATATYPE_H
#define DATATYPE_H

// Defining data structure
typedef int* Data;
typedef struct {
    char *str1;
    char *str2;
} Key_struct;
typedef Key_struct* Key;

// Function prototypes for Key operations
Key key_ini();
void key_set(Key key, char *str1, char *str2); // Set key
int key_comp(Key key1, Key key2); // Compare keys
void key_print(Key key); // Print key
void key_free(Key key); // Free key memory
char * string_dup(char *str); // Duplicate strings

// Function prototypes for Data operations
Data data_ini(); // Initialize data
void data_set(Data data, int intdata); // Set data
void data_print(Data data); // Print data
void data_free(Data data); // Free data memory

#endif // DATATYPE_H

