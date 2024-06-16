#include <stdio.h>

int main()

{
    // Array is a collection/data structure of a number of data values of same type
    float prices[] = {5, 10, 15, 20, 25};
    int x, y;

    x = sizeof(prices);
    y = sizeof(prices[1]);

    for (int i = 0; i < (x/y); i++)
    {
        printf("$%.2f", prices[i]);
    }
    return 0;
}