#include <stdio.h>

int main ()
{
    /*
    int num [3][3] = {
                        {2,4,6}
                        {1,2,3}
                        {4,3,2}
    }
    */
    int num[3][3];  // first [] is for rows whcih can be empty.
                    // second [] is for columns which needs to be specified.
    int rows, columns;

    num[0][0] = 2;
    num[0][1] = 4;
    num[0][2] = 6;
    num[1][0] = 1;
    num[1][1] = 2;
    num[1][2] = 3;
    num[2][0] = 4;
    num[2][1] = 3;
    num[2][2] = 2;

    rows = sizeof(num)/ sizeof(num[0]);
    columns = sizeof(num[1])/ sizeof(num[2][3]);

    printf("%d bytes\n", sizeof(num));
    printf("%d bytes\n", sizeof(num[1]));
    printf("%d bytes\n", sizeof(num[2][3]));
    
    printf("# of rows : %d", rows);
    printf("\n# of columns : %d\n", columns);

    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++ )
        {
            printf("%d", num[i][j]);
        }
        printf("\n");
    }
    return 0;
}