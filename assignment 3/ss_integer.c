#include <stdio.h>

int main() {
	// Creating the 7-digit integer displays for numbers 0 through 9
	const char seg[10][3][3] = {{{' ','_',' '},{'|',' ','|'},{'|','_','|'}},
		{{' ',' ',' '},{' ',' ','|'},{' ',' ','|'}}, 
		{{' ','_',' '},{' ','_','|'},{'|','_',' '}},
		{{' ','_',' '},{' ','_','|'},{' ','_','|'}},
		{{' ',' ',' '},{'|','_','|'},{' ',' ','|'}},
		{{' ','_',' '},{'|','_',' '},{' ','_','|'}},
		{{' ','_',' '},{'|','_',' '},{'|','_','|'}},
		{{' ','_',' '},{' ',' ','|'},{' ',' ','|'}},
		{{' ','_',' '},{'|','_','|'},{'|','_','|'}},
		{{' ','_',' '},{'|','_','|'},{' ','_','|'}}};

	char option = 'Y'; // Variable to keep track of user input (whether they want to continue or not)
	while (option == 'Y' || option == 'y') {// While the user wants to continue...
	
		int sign = 0; // Variable to store the sign of the integer inputted
		int length = 0; // Variable to keep track of the length of the integer inputted
		int digit; // Variable to get the integer that the user wants to display in 7-digit integer display
		int numArray[100]; // Create an integer array with length 100
		printf("Please input an integer (no decimals): ");
		scanf(" %d", &digit); // Storing user's input in variable digit

		// Changing the value of sign depending on whether digit is a 0, a negative number, or positive number
		if (digit < 0) { // If the user inputted a negative number...
			sign = -1; // Change sign to -1
			digit = 0 - digit; // Make digit a positive number
		}
		else if (digit == 0) {// Else if the user inputted a zero...
			sign = 0; // Change sign to 0
		}
		else { // Else if the user inputted a positive number...
			sign = 1; // Change sign to 1
		}

		// Storing each number of the inputted integer into the array
		while (digit != 0) {// While the digit is not 0...
			numArray[length] = digit % 10; // Store the last number into the first index of the array
			length = length + 1; // Increment length by 1
			digit = digit / 10; // Divide digit by 10 so that we can get the next number
		}

		length = length - 1; // Decrement length by 1 because it is not needed after we unnecessarily incremented it by 1 for the last number previously

		if (sign == 0) {// If the number in the integer is a 0...
			int x; // Variable for first for loop
			int y; // Variable for second for loop
            // Two for loops to print all of the characters needed to create a 0
			for (x = 0; x < 3; x++) {
				for (y = 0; y < 3; y++)
					printf("%c", seg[0][x][y]);
				printf("\n");
			}
		}
		else { // If the number in the integer is not a 0...
			int x; // Variable for first for loop
			int y; // Variable for second for loop
			int z; // Variable for third for loop
			for (x = 0; x < 3; x ++) {
				if (sign == -1) { // If the user inputted a negative number...
				    if (x == 1) { // When x is 1 (basically in the middle between 0 and 3)
						printf("_"); // Put a minus sign
				    }
					else { // Otherwise...
						printf(" "); // Do not put anything
					}
				}	
				
				// For loop to start displaying the integer starting at the last number as the array has the integer in reverse order
				for (y = length; y >= 0; y --)
				{
					for (z = 0; z < 3; z ++)
						printf("%c",seg[numArray[y]][x][z]); // Display the integer
				}
				printf("\n");
			}
		}
		
		printf("Would you like to continue entering integers? Y = yes, N = no\n"); // Ask the user if they'd like to continue
		scanf(" %c", &option); // Get user input
		
	}
	while ((option=='Y') || (option=='y')); { // While the user wants to continue...
        return 0; // Return 0
	}

}
