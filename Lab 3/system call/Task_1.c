#include <stdio.h>
#include <stdlib.h>

int compare(char *string1, char *string2)
{
    for (int i = 0; string1[i] != '\0'; i++)
    {
        if (string1[i] != string2[i])
        {
            return 0;
        }
    }
    return 1;
}
int main(int argv, char *argc[]) // argc is the number of arguments being passed into your program from the command line and argv is the array of arguments
{
    if (argv != 2)
    {
        printf("File name not passing\n");
        exit(0);
    }
    FILE *fp;
    fp = fopen(argc[1], "w");
    printf("Pleae Enter -1 for stopping\n");
    char input[100];
    gets(input);
    while (!compare(input, "-1"))
    {
        fprintf(fp, "%s\n", input);
        gets(input);
    }
    fclose(fp);
    return 0;
}