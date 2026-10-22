#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("pass c file \n");
        return -1;
    }
    char str[200];
    FILE *fptr;
    fptr = fopen(argv[1], "r");
    if (file_validation(argv[1]) == FAILURE)
    {
        printf("input file is not valid\n");
        printf("pass ___.c file \n");
        return 1;
    }
    if (fptr == NULL)
    {
        printf("Error in opening file :\n");
        return 1;
    }
    while (fgets(str, sizeof(str), fptr) != NULL)
    {
        tokenize(str);
    }
    fclose(fptr);

    return 0;
}