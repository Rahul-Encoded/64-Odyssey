#include <stdio.h>
#include <string.h>

int main()
{
    char names[][25] = {"Shreya", "Preeti", "Devanshi"};
    /*
    name[3] = {"Khushi"};
    */
   strcpy(names[3], "Khushi");

   for (int i = 0; i < sizeof(names)/ sizeof(names[2]); i++)
   {
    printf("%s\n", names[i]);
   }
    return 0;
}