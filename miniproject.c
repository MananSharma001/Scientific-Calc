#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define note "Invalid input, please enter a valid operation"

void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void factorial();
void power();
void square();
void cube();
void squareroot();
void DtoB();
int binaryToDecimal();
int DigitalToOctal();
int OctalToDigital();

int main() {
    printf("\t\tWelcome to the scientific calculator!!\n\n");
    int choice;
    
    printf("******* Press 0 to quit the program ********\n");
    printf("Enter 1 for Addition\n");
    printf("Enter 2 for Subtraction\n");
    printf("Enter 3 for Multiplication\n");
    printf("Enter 4 for Division\n");
    printf("Enter 5 for Modulus\n");
    printf("Enter 6 for Power\n");
    printf("Enter 7 for Factorial\n");
    printf("Enter 8 for Square\n");
    printf("Enter 9 for Cube\n");
    printf("Enter 10 for Square Root\n");
    printf("Enter 11 to convert Decimal number to Binary\n");
    printf("Enter 12 to conver Binary number to Digital\n");
    printf("Enter 13 to convert Digitaal number to Octal\n");
    printf("Enter 14 to convert Octal number to Digital\n\n");

    while (1) {
        printf("\n\nEnter the operation you want to perform: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                modulus();
                break;
            case 6:
                power();
                break;
            case 7:
                factorial();
                break;
            case 8:
                square();
                break;
            case 9:
                cube();
                break;
            case 10:
                squareroot();
                break;
            case 11:
                DtoB();
                break;

            case 12:
            binaryToDecimal();
            break;
            
            case 13:
            DigitalToOctal();
            break;

            case 14:
            OctalToDigital();
            break;

            case 0:
                exit(0);
            default:
                printf("\n********** %s ***********\n", note);
        }
    }
    return 0;
}

void addition() {
    printf("Enter the numbers you want to add: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("The sum of %d and %d is %d\n", a, b, a + b);
}

void subtraction() {
    printf("Enter the numbers you want to subtract: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("The subtraction of %d and %d is %d\n", a, b, a - b);
}

void multiplication() {
    printf("Enter the numbers you want to multiply: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("The multiplication of %d and %d is %d\n", a, b, a * b);
}

void division() {
    printf("Enter the numbers you want to divide: ");
    int a, b;
    scanf("%d %d", &a, &b);
    if (b == 0) {
        printf("Division by zero is not allowed.\n");
    } else {
        printf("The division of %d and %d is %.2f\n", a, b, (float)a / b);
    }
}

void modulus() {
    printf("Enter the numbers you want to find modulus of: ");
    int a, b;
    scanf("%d %d", &a, &b);
    if (b == 0) {
        printf("Modulus by zero is not allowed.\n");
    } else {
        printf("The modulus of %d and %d is %d\n", a, b, a % b);
    }
}

void factorial() {
    int n, factorial = 1;
    printf("Enter the number you want the factorial of: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        printf("Factorial of %d is %d\n", n, factorial);
    }
}

void power() {
    double base, exponent;
    printf("Enter the base and the power: ");
    scanf("%lf %lf", &base, &exponent);
    double result = pow(base, exponent);
    printf("The result of %.2lf ^ %.2lf is %.2lf\n", base, exponent, result);
}

void square() {
    double num;
    printf("Enter the number you want the square of: ");
    scanf("%lf", &num);
    double result = num * num;
    printf("The square of %.2lf is %.2lf\n", num, result);
}

void cube() {
    double num;
    printf("Enter the number you want the cube of: ");
    scanf("%lf", &num);
    double result = num * num * num;
    printf("The cube of %.2lf is %.2lf\n", num, result);
}

void squareroot() {
    double num;
    printf("Enter the number you want the square root of: ");
    scanf("%lf", &num);
    if (num < 0) {
        printf("Square root is not defined for negative numbers.\n");
    } else {
        double result = sqrt(num);
        printf("The square root of %.2lf is %.2lf\n", num, result);
    }
}

void DtoB() {
    int n;
    printf("Enter the decimal number to convert to binary: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Binary representation is not defined for negative numbers.\n");
    } else {
        int binary[32]; // Assuming a maximum of 32-bit binary representation
        int i = 0;

        while (n > 0) {
            binary[i] = n % 2;
            n /= 2;
            i++;
        }

        if (i == 0) {
            printf("Binary representation: 0\n");
        } else {
            printf("Binary representation: ");
            for (int j = i - 1; j >= 0; j--) {
                printf("%d", binary[j]);
            }
            printf("\n");
        }
    
    }
   
}
int binaryToDecimal() {
    int binary;
    printf("Enter a binary number: ");
    scanf("%d", &binary);
    
    int decimal = 0, base = 0;
    
    while (binary > 0) {
        int digit = binary % 10;  // Get the last digit of the binary number
        decimal += digit * pow(2, base);  // Convert and add to the decimal
        binary /= 10;  // Remove the last digit from the binary number
        base++;  // Increment the power of 2
    }
    
    printf("Decimal equivalent: %d\n", decimal);
    return decimal; // Return the decimal equivalent
}

int DigitalToOctal(){
    int number,oct=0,num,i=0;
    printf("Enter the Decimal number to convert into Octal: ");
    scanf("%d",&number);

    while(number != 0){
        num= number%8;
        oct=oct+num*pow(10,i);
        number=number/8;
        i++;
}
printf("Octal value is: %d ",oct);
}


int OctalToDigital() {
    int octalnum,digitalnum=0,i=0;

    printf("Enter an octal number: ");
    scanf("%d", &octalnum);

    while (octalnum != 0) {
        int remainder = octalnum % 10;
        digitalnum += remainder * (1 << (3 * i));
        octalnum /= 10;
        i++;
    }

    printf("Decimal equivalent: %d\n", digitalnum);

    return 0;
}
