#include <stdio.h>
#include <math.h>



int main(void)
{
    int a, b, c;
    char op, rep;


    rep = 'y';

   while(rep == 'y')
    {

    printf("----------------------------------------------------\n");
    printf("This is a simple calculator\n");
    printf("Please enter two numbers and then choose the operation\n");
    printf("Number 1:");
    scanf(" %d", &a); //Spaces in the scanf-Funktion are important as to keep input 
                    //clean of newlines and whitespace
    printf("number 2:");
    scanf(" %d", &b);

    printf("\nWhat operation do you want to make?\n");
    printf("Input values\nNr.1 -> %d\nNr.2 -> %d\n\n", a, b);
    printf("Possible operations:\nAddition (+)\nSubstraktion (-)\nMultiplikation (*) \nDivision (/)\n");

    

    scanf(" %c", &op);

    if (op == '+') //Addition
    {
        c = a + b;
        printf("Addition: %d + %d = %d\n", a, b, c);
    }

    if (op == '-') //Substraktion
    {
        c = a - b;
        printf("Substraktion: %d - %d = %d\n",a, b, c);
    }

    if (op == '*') //Multiplikation
    {
        c = a * b;
        printf("Multiplikation: %d * %d = %d\n",a, b, c);
    }

    if (op == '/') //Division
    {
        c = a / b;
        printf("Division: %d / %d = %d\n",a, b, c);
    }

    printf("\nDo you want to make another calculation?\n");
    printf("[y] - yes\n[n] - no\n");
    
    scanf(" %c", &rep);
    
    }


    printf("Programm ended successfully, thank you for using\n\n");
    return 0;
}