#include <stdio.h>

// Function that is a converter for celsius and fahrenheit
int celsius_fahrenheit() {
    
    // char c will store the character that the user inputs to indicate whether they want to convert to celsius or fahrenheit
    char c;
    
    // float temp will store the temperature that the user inputs
    float temp;
    
    // While the user has not given a valid character (C or F), it will keep prompting them to do so
    while ((c!='C') && (c!='F')) {
        printf("Enter C (to convert from celsius to fahrenheit) or F (to convert from fahrenheit to celsius): \n");
        // Get user input for whether they want to convert to celsius or fahrenheit
        scanf(" %c", &c);
        
    }
    
    printf("Enter temperature: \n");
    // Get user input for the temperature
    scanf(" %f", &temp);
    
    // If the user inputs C...
    if (c=='C') {
        printf("%f degrees celsius in fahrenheit is ", temp);
        // Calculate fahrenheit using formula below (formula found on Google)
        temp = (temp * 9/5) + 32;
    }
    // If the user inputs F...
    else if (c == 'F') {
        printf("%f degrees fahrenheit in celsius is ", temp);
        // Calculate celsius using the formula below (formula found on Google)
        temp = (temp-32)*5/9;
    }
    
    // Display calculated temperature
    printf("%f degrees \n", temp);
    
    return 0;
}

int centimetre_inch() {
    
    // char c will store the character that the user inputs to indicate whether they want to convert to centimetres or inches
    char c;
    
    // float length will store the length that the user inputs
    float length;
    
    // While the user has not given a valid character (C or I), it will keep prompting them to do so
    while ((c!='C') && (c!='I')) {
       
        printf("Enter C (to convert from centimetres to inches) or I (to convert from inches to centimetres: \n");
         // Get user input for whether they want to convert to centimetres or inches
        scanf(" %c", &c);
        
    }
    
    printf("Enter length: \n");
    // Get user input for the length
    scanf(" %f", &length);
    
    // If the user inputs C...
    if (c=='C') {
        printf("%f centimetres in inches is ", length);
        // Calculate inches using the formula below (formula found on Google)
        length = (length/2.54);
    }
    // If the user inputs I...
    else if (c == 'I') {
        printf("%f inches in centimetres is ", length);
        // Calculate centimetres using the formula below (formula found on Google)
        length = (length*2.54);
    }
    
    //Display calculated length
    printf("%f\n", length);
    
    return 0;
}

int kilogram_pound() {
    
    // char c will store the character that the user inputs to indicate whether they want to convert to centimetres or inches
    char c;
    
    // float weight will store the weight that the user inputs
    float weight;
    
    // While the user has not input either K or P, it will keep prompting them to do so
    while ((c!='K') && (c!='P')) {
       
        printf("Enter K (to  convert from kilograms to pounds) or P (to convert from pounds to kilograms): \n");
        // Get user input for whether they want to convert to kilograms or pounds
        scanf(" %c", &c);
        
    }
    
    printf("Enter weight: \n");
    // Get user input for weight
    scanf(" %f", &weight);
    
    // If the user inputs K...
    if (c=='K') {
        printf("%f kilograms in pounds is ", weight);
    // Calculate pounds using the formula below (formula found on Google)
        weight = weight*2.205;
    }
    else if (c == 'P') {
        printf("%f pounds in kilograms is ", weight);
    // Calculate kilograms using the formula below (formula found on Google)
        weight = weight/2.205;
    }
    
    // Display the resulting weight
    printf("%f\n", weight);
    
    return 0;
}

int meter_feet() {
    
    // char c will store the character that the user inputs to indicate whether they want to convert to centimetres or inches
    char c;
    
    // float length will store the length that the user inputs
    float length;
    
    // While the user has not given a valid character (M or F), it will keep prompting them to do so
    while ((c!='M') && (c!='F')) {
       
        printf("Enter M (to convert from meters to feet) or F (to convert from feet to meters): \n");
        // Get user input for whether they want to convert to feet or meters
        scanf(" %c", &c);
        
    }
    
    printf("Enter length: \n");
    
    // Get user input for length
    scanf(" %f", &length);
    
    // If the user inputs M...
    if (c=='M') {
        printf("%f meters in feet is ", length);
    // Calculate feet using the formula below (formula found on Google)
        length = length*3.281;
    }
    else if (c == 'F') {
        printf("%f feet in meters is ", length);
    // Calculate meters using the formula below (formula found on Google)
        length = length/3.281;
    }
    
    // Display the resulting length
    printf("%f\n", length);
    
    return 0;
}

int main() {
    
    // char c is used to store user input for the desired conversion
    char c;
    
    // While the user has not input a valid character (1, 2, 3, 4, q, or Q)
    while (1) {
        
        printf("Enter a character (1 for celius-farhenheit converter, 2 for centimetre-inch converter, 3 for kilogram-pound converter, 4 for meter-feet converter, and q or Q to quit): \n");
        
        // Get user's input for desired converter
        scanf(" %c", &c);

        // If user inputs 1...
        if (c == '1') {
            // Use celsius-fahrenheit converter
            celsius_fahrenheit();
        }
        // If user inputs 2...
        else if (c == '2') {
            // Use centimetre-inch converter
            centimetre_inch();
        }
        // If user inputs 3...
        else if (c == '3') {
            // Use kilogram-pound converter
            kilogram_pound();
        }
        // If user inputs 4...
        else if (c == '4') {
            // Use meter-feet converter
            meter_feet();
        }
        // If user inputs q...
        else if (c == 'q') {
            // Quit
            exit(0);
        }
        // If user inputs Q...
        else if (c == 'Q') {
            // Quit
            exit(0);
        }
    }

    return 0;
}


