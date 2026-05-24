#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file_ptr;
    char ch;
    file_ptr = fopen("test_code.c","r");
    if(file_ptr == NULL)
    {
        printf("Error: couldn't open the file.\n");
        return 1;
    }

    printf("----starting file stream scan ---\n");

    while((ch = fgetc(file_ptr)) != EOF)
    {
        putchar(ch);
    }

    printf("\n----scan completed successfully ----\n");

    fclose(file_ptr);
    return 0;
}