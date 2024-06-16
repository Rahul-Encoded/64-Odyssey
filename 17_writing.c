#include <stdio.h>

int main()
{
    FILE *pF = fopen("test.html", "w");  // "w" for writing, "a" for appending, "r" for reading
                                        //  in order to create file at a specific location.. You need to enter the location/ path...eg. E:\\C Projects\\BroCode\\test.html

    fprintf(pF, "<html>\n<head>\n<title>\nTest\n</title>\n</head>\n<body>\n<h3>\nHello!!</h3>\n</body>\n</html>");

    fclose(pF);    //A good practice to always close an opened file.

    /*
    if (test.html == 0)
        {
            printf("File deleted successfully!!");
        }
    else
        {
            printf("The file has not been deleted!!");
        }
    */
    return 0;
}