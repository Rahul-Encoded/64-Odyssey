#include <stdio.h>

int digitSum(int n){
    if(n == 0) return 0;
    return (digitSum(n/10) + (n % 10));
}

int main() {
    // Your code goes here
    int n;
    printf("Enter your #: ");
    scanf("%d", &n);
    printf("Sum of digits = %d", digitSum(n));    
    return 0;
}