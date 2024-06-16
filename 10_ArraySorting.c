#include <stdio.h>

void swap (int num[], int size)
{
    for (int i = 0; i < (size - 1); i++)    // for loop for no. of passes
    {
        for (int j = 0; j < size - i - 1; j++)  // for loop for no. of comparisons in each pass
        {
            if (num[j]< num[j+1])
            {
                int temp = num [j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
}

void printArray(int num[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d", num[i]);
    }
    printf("\n");
}

int main()
{
    int num[] = {4,6,2,1,3,8,7,9};
    int size = sizeof(num)/ sizeof(num[2]);

    printf("Before BubbleSort : \n");

    printArray(num, size);

    swap(num, size);
    printf("After BubbleSort : \n");

    printArray(num, size);        

    return 0;
}