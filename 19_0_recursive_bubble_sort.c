#include <stdio.h>
#include <stdlib.h>

void bS(int arr[], int end){
    if(end == 0) return;
    
    for(int i = 0; i < end; i++){
        if(arr[i] > arr[(i+1)]){
        swap(arr[i], arr[(i+1)]);
    }
    }
    end--;
    bS(arr, end);
}

void bubbleSort(int arr[], int n) {
    bS(arr, n-1);
}

int main()
{
    int n;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        int c;
        printf("Enter element : ");
        scanf("%d", &c);
        a[i] = c;
    }

    bS(a, n);

    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }

    return 0;
}