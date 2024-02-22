#include <stdio.h>

// Function that returns the float power given a float base and integer exponent
float exponent_calculator(float base, int exponent){
    float p;

    // If the user inputs 0 as the base but a non-zero number as the exponent
    if ((exponent != 0) && (base == 0)) {
	    return 0;
    }
    // If the user inputs 0 as the exponent, return 1 because anything to the power of 0 is 1
    else if (exponent == 0){
        return 1;
    }
    
    // If the user inputs a number less than 0 as the exponent, use the formula 1/(a^n)... given in assignment
    else if(exponent < 0){
        return 1/exponent_calculator(base, -exponent);
    }
    
    // If the user inputs a number greater than 0 and it is an even number, use the formula (a^(n/2))^2... given in assignment
    else if(exponent % 2 == 0){
        p = exponent_calculator(base,exponent/2);
        return p*p;
    }
    
    // If the user inputs a number greater than 0 and it is an odd number, use the formula ((a^((n-1)/2))^2)*a... given in assignment
    else{
        p = exponent_calculator(base, (exponent-1)/2);
        return p*p*base;
    }
}

// Main function
int main()
{   
    // float base will be the base the user inputs
    float base;
    // integer exponent will be the exponent the user inputs
    int exponent;
    
    // float result will keep be used to get the resulting power
    float result;
    
    // while true...
    while(3>2){
        
        printf("Enter base:\n");
        // Get input for base
        scanf("%f", &base);
    
        printf("Enter exponent:\n");
        // Get input for exponent
        scanf("%d", &exponent);
        
        // If the user inputs 0 as the exponent, exit loop
        if(exponent == 0) {
		result = exponent_calculator(base, exponent);
		printf("%f\n", result);
		break;
	}
	
        // Calculate the power and store in result and display it
        result = exponent_calculator(base,exponent);
        printf("%f\n",result);
    }
    
    // Return an integer, in this case, 0
    return 0;
}
