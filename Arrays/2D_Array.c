#include <stdio.h>

int main()
{

    //Declaration of a two-dimensional array
    int numbers[2][3] = {
                        {1, 2, 3},
                        {4, 5, 6}
    };

    int rows = sizeof(numbers)/sizeof(numbers[0]);
    int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);

    printf("rows %d\n", rows);
    printf("columns %d\n", columns);
    //Using nested loops for looking at the 2D array
    for (int i = 0; i < 2; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            printf("%d", numbers[i][j]);
        }
    }

    return 0;
}
