#include <stdio.h>
#include <stdlib.h>
#define sizeLimit 100

char *SpaceRemover(const char *str);
int main()
{
    char str[sizeLimit];
    char *UpdatedString;

    printf("Enter any string: ");
    gets(str);

    UpdatedString = SpaceRemover(str);

    printf("\n'%s'", UpdatedString);

    return 0;
}
char *SpaceRemover(const char *str)
{
    int i, j;
    char *UpdatedString;
    UpdatedString = (char *)malloc(sizeLimit);
    i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            UpdatedString[j] = ' ';
            j++;
            while (str[i] == ' ')
                i++;
        }
        UpdatedString[j] = str[i];
        i++;
        j++;
    }
    UpdatedString[j] = '\0';

    return UpdatedString;
}