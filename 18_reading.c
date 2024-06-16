#include<stdio.h>

int main()
{
    FILE *pf = fopen ("test.html", "r");

    char buffer[200];
    if (pf == NULL)
    {
        printf("File doesn't exist.");
    }
    else
    {
        while(fgets(buffer, 255, pf) != NULL)
            {
                printf("%s", buffer);
            }
    }
    fclose(pf);
    return 0;
}