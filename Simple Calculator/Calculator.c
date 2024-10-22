#include <stdio.h>
#include <math.h>

int main(void) {
    float num1, num2, result = 0.0;
    char op;
    int validInput;
    char continueCalc;

    do {
        // Input validation for the first number
        do {
            printf("Enter your first number: ");
            validInput = scanf("%f", &num1);
            while (getchar() != '\n'); // Clear the input buffer
            if (!validInput) {
                printf("Invalid input. Please enter a valid number.\n");
            }
        } while (!validInput);

        // Input validation for the operation symbol
        do {
            printf("Enter operation symbol (+, -, *, /, %, ^): ");
            validInput = scanf(" %c", &op);
            while (getchar() != '\n'); // Clear the input buffer
            if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^') {
                printf("Invalid operation symbol. Please enter a valid operation symbol.\n");
                validInput = 0;
            }
        } while (!validInput);

        // Input validation for the second number
        do {
            printf("Enter your second number: ");
            validInput = scanf("%f", &num2);
            while (getchar() != '\n'); // Clear the input buffer
            if (!validInput) {
                printf("Invalid input. Please enter a valid number.\n");
            }
        } while (!validInput);

        switch (op) {
        case '+': // Addition operation
            result = num1 + num2;
            break;
        case '-': // Subtraction operation
            result = num1 - num2;
            break;
        case '*': // Multiplication operation
            result = num1 * num2;
            break;
        case '/': // Division operation
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed\n");
                return 1;
            }
            break;
        case '%': // Modulus operation
            if ((int)num2 == 0) {
                printf("Error: Division by zero is not allowed\n");
                return 1;
            } else {
                result = (int)num1 % (int)num2;
            }
            break;
        case '^': // Exponentiation operation
            result = pow(num1, num2);
            break;
        default:
            printf("Error: Invalid operation\n");
            return 1;
        }

        printf("The result is: %f\n", result);

        // Ask the user if they want to perform another operation
        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &continueCalc);
        while (getchar() != '\n'); // Clear the input buffer

    } while (continueCalc == 'y' || continueCalc == 'Y');

    return 0;
}