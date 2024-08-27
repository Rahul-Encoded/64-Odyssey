#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int end, int n)
{
    
    if(end == n) return;
    
    for(int i = end; i > 0; i--){
        if(arr[i] < arr[i-1]){
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
    }
        end++;
        insert(arr, end, n);
}
 
void insertionSort(int arr[], int n)
{
    
    insert(arr, 1, n);
}

int main() {
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

    insertionSort(a, n);

    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }

    return 0;
}