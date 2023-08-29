#include <stdio.h>
#include <stdlib.h>


int input(int numbers[2][3])
{
    printf("\n\tInput desired values\n");

    for (int i = 0; i<2;i++)
    {
        for (int j = 0; j < 3; j++)
        {
    printf("\tColumn Nr.%d\tRow Nr.%d:", j + 1, i + 1);
    scanf("%i", &numbers[i][j]);
        }
    }
}


int main()
{

    //Declaration of a two-dimensional array
    int numbers[2][3] = {
                        {1, 2, 3},
                        {4, 5, 6}
    };
    char rep = 'y';


    while (rep == 'y')
    {
    printf("\tWelcome!\n\tThis program creates a little two-dimensional array\n");
    printf("\tArray is of a 2x3 Dimension\n");
    input(&numbers);

    int rows = sizeof(numbers)/sizeof(numbers[0]);
    int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);

    printf("\n\tResulting Array:");
    printf("\n");
    //Using nested loops for looking at the 2D array
    for (int i = 0; i < 2; i++)
    {
        printf("\t\t");
        for ( int j = 0; j < 3; j++)
        {
            printf("%d", numbers[i][j]);
        }
         printf("\n");
    }
    printf("\n\tDo you want to try again with different values?\n");
    printf("\t[y] = yes\n\t[n] = no\n\n\tUser Choice:");
    
    
    scanf(" %c", &rep);
    printf("\n------------------------------------------------------------------\n\n");
    }


    printf("\nProgramm ended successfully\n");
    return 0;
}
