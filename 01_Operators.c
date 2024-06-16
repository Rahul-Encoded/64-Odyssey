#include <stdio.h>

int main ()
{
    int a,b,c,d,e,f,g,h,i,j,k,l;
    
    printf("Enter 2 nos. of your desire : ");
    scanf("%d%d", &a, &b);

//logical operators give true and false as values and are usedin conditional statements.
    c = a&&b;
    d = a||b;
//bitwise operators are used in binary  operations
    e = a&b;
    f = a|b;
    g = a^b;
    h = -a;
    i = a<<2;
    j = a>>3;
    k = a&b;


    printf("a&&b = ", c);
    printf("\na||b = ", d);
    printf("\na&b = ", e);
    printf("\na|b = ", f);
    printf("\na^b = ", g);
    printf("\n-a = ", h);
    printf("\na<<2 = ", i);
    printf("\na>>3 = ", j);
    printf("!(a&b) = ", k);

    return 0;
}