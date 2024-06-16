#include<stdio.h>
#include<string.h>

int main()
{
    char name1[15] = "Shreya";
    char name2[15] = "Priti";   // You can keep [] empty when you assign an array a value. 
    //But due to the reason we are swapping strings here, we need to assign them a size, otherwise string with big size won't get the swapped value.
    char temp[15];
    
    printf("Before swapping :\nname1 = %s\nname2 = %s\n", name1, name2);

    /*
    you can't just
    temp[] = name1[]
    */

   strcpy(temp, name1);
   strcpy(name1, name2);
   strcpy(name2, temp);
    
    printf("\nAfter swapping : ");
    printf("\nname1 = %s", name1);
    printf("\nname2 = %s", name2);
   return 0;
}