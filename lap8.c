#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void add(float* operand1, float operand2);
void chk_int_input(float *input);
void multiply(float* operand1, float operand2);
void divide(float* operand1, float operand2);
void subract(float* operand1, float operand2);

 
int main(){   
float operand1;
float operand2;
float* result = &operand1;
char operation;
    bool status = true;
    start:
    printf("Start the calculations :)\n");
    printf("Enter the first operand: ");
    chk_int_input(&operand1);
    do{
    printf("What operation do you want to perform?\n>> ");
    scanf(" %c", &operation);
        printf("Enter the second operand: ");
        chk_int_input(&operand2);
        switch(operation){
            case '+': add(result, operand2);
            break;
            case '-': subract(result, operand2);
            break;
            case '*': multiply(result, operand2);
            break;
            case '/': divide(result, operand2);
            break;
            case '#': printf("Goodbye :(\n");
            break;
            case '@': goto start;
            break;
            default: printf("Error :(");
            goto start;
        }
}while(status);
    return 0;
}

void add(float* operand1, float operand2){
    printf("%f + %f = %f\n", *operand1, operand2, (*operand1 + operand2));
    *operand1 = *operand1 + operand2;
}
void subract(float* operand1, float operand2){
    printf("%f - %f = %f\n", *operand1, operand2, (*operand1 - operand2));
    *operand1 = *operand1 - operand2;
}

void multiply(float* operand1, float operand2){
    printf("%f * %f = %f\n", *operand1, operand2, (*operand1 * operand2));
    *operand1 = *operand1 * operand2;
}

void divide(float* operand1, float operand2){
    printf("%f / %f = %f\n", *operand1, operand2, (*operand1 / operand2));
    *operand1 = *operand1 / operand2;
}

void chk_int_input(float *input)
{
    int result;
    do
    {
        result = scanf("%f", input);
        fflush(stdin);

        if (result != 1)
        {
            printf("Invalid input, Input must be an INTEGER\n>> Please try again: ");
        }
    } while (result != 1);
}