#include <stdio.h>
#include <stdlib.h>

float md_exp(void); // Setting up all of the functions
float md_sub_exp(float sub_exp);
float sim_exp(void);
float sim_sub_exp(float sub_exp);
float get_num(void);
char get_op(void);

char get_op(void) { // Function to get the next operator
    char op = ' '; // Initializing variable op to store the operator in
	while (op == ' ') // While op is an empty space...
		scanf("%c", &op); // Get the next operator
	return op; // Return the operator
}

float get_num(void) { // Function to get the next number
    float num; // Initializing variable num to store the number in
    scanf("%f", &num); // Getting the next number
    return num; // Returning the number
}

float sim_sub_exp(float sub_exp) { // Function to return the value of the current sim_expression 
    char next_op = get_op(); // Variable next_op stores the next operator in it
    
    if (next_op == '\n') { // If the next operator is a newline character...
        ungetc(next_op, stdin); // Push back one character
        return sub_exp; // Return sub_exp (the argument)
    }
    else { // Otherwise, if the next operator is NOT a newline character...
        float next_md_exp = md_exp();
        if (next_op == '+') { // If the next operator is a plus sign...
            sim_sub_exp(sub_exp + next_md_exp); // Do a recursive call with the argument adding sub_exp and next_md_exp
        }
        else { // Otherwise, if the next operator is a minus sign...
            sim_sub_exp(sub_exp - next_md_exp); // Do a recursive call with the argument substracting next_md_exp from sub_exp
        }
    }
}

float sim_exp(void) { // Function to return the value of the next sim_expression
    float m = md_exp(); // Storing the result of md_exp() in float m
    return sim_sub_exp(m); // Returning the value of the next sim_expression
}


float md_sub_exp(float sub_exp) { // Function to return the value of the current md_expression
    char next_op = get_op(); // Getting the next operator and storing it in char next_op
    if ((next_op == '+') || (next_op == '-') || (next_op == '\n')) { // If the next operator is an addition, subtraction, or newline character...
        ungetc(next_op, stdin); // Push back one character
        return sub_exp; // Return sub_exp (the argument)
    }
    else { // Otherwise, if the next operator is not an addition, subtraction, or newline character...
        float next_num = get_num(); // Get the next number and store in float next_num
        if (next_op=='*') { // If the next operator is multiplication...
            md_sub_exp(sub_exp * next_num); // Do a recursive call with the argument multiplying sub_exp and next_num
        }
        else { // Otherwise, if the next operator is a division sign...
            md_sub_exp(sub_exp / next_num); // Do a recursive call with the argument dividing sub_exp by next_num
        }
    }
    
}

float md_exp(void) { // Function to return the value of the next md_expression
    float m = get_num(); // Get the next number and store in float m
    return md_sub_exp(m); // Returning the value of the next md_expression
}


int main() { // Main function
    while(2==2){ // While true...
        char response; // Variable to store user's input for whether they want to continue or not
        float result; // Variable to store user's arithmetic expression
        printf("Enter an arithmetic expression: ");
        result = sim_exp(); // Getting the artithmetic expression
        printf("Result: %.2f\n", result); // Printing the result
        printf("Would you like to continue? \n");
        scanf(" %c", &response); // Getting user's response
        if((response == 'Y') || (response == 'y')){ // If the response is a yes...
            main(); // Execute main function again
        }
        else if ((response == 'N') || (response == 'n')){ // If the response is a no...
            break; // End loop
        }
        else{ // Otherwise...
            exit(EXIT_FAILURE); // Terminate program
        }
        return 0;
    }
}
