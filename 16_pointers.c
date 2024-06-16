#include <stdio.h>

void printAge(int *pAge)
{
   printf("You are %d years old\n", *pAge); //dereference means (here) print value at the stored address
}

int main()
{
   // pointer = a "variable-like" reference that holds a memory address to another variable, array, etc.
   //           some tasks are performed more easily with pointers
   //           * = indirection operator (value at address)
   //           less time in program execution.
   //           Working on the original variable.
   //With the help of pointers, we can create data structures (linked-lists, stacks, queues)
   //            Returning more than 1 values from functions
   //            Searching and sorting large data very easily
   //            Dynamically memory allocation

   int age = 21;
   int *pAge = &age; // integer pointer named pAge is set to the address of age
//  int y = *pAge; //integer y is set to the value/thing pointed to by pAge.

   printAge(pAge);

   //printf("address of age: %p\n", &age);
   //printf("value of pAge: %p\n", pAge);
   //printf("size of age: %d bytes\n", sizeof(age));
   //printf("size of pAge: %d bytes\n", sizeof(pAge));
   //printf("value of age: %d\n", age);
   //printf("value at stored address: %d\n", *pAge); //dereferencing

   return 0;
}