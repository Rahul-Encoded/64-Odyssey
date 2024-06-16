#include <stdio.h>
enum day {Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 7};

int main()
{
    /*
        enum stands for enumeration.
        enum is a user defined type of named integer identifiers.
        enum helps to make a program more readable.
        enums can be either declared inside or outside of the main function.
    */

   enum day today = 6;

    if (today == Saturday || today == Sunday )
    {
        printf("It's the weekend!!");
    }

    else
    {
        printf("GO TO WORK!!!");
    }
   return 0;
}