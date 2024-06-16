#include <stdio.h>
#include <string.h>

int main()
{
    char name[25];  // here I need to specify the lengt of the string (or coloumn of the array)
    printf("Enter your name :");
    //scanf("%s", name); 
    
    //[We do not need to specify the address of the variable name here (&) because here the variable (or arrey) already points to the 1st element of the array.]
    
    // Why did I not use scanf?
    // Coz' it terminates if it encounters a white space./ only takes input until it encounters white space.

    //So we will use a function called fget.
    //fget function takes in only 3 parameters.
    //First parameter is the name of the string variable or array.
    //Second parameter id the size of the array/ string variable.
    //Third parameter is stdin which means standard input, i.e, we are taking input from the keyboard.

    fgets(name, sizeof(name), stdin);

    printf("%s", name);

    return 0;

}
