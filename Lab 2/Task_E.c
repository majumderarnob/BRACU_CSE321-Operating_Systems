#include <stdio.h>
#include <conio.h>
int main()
{
    char str[30];
    char *pointer1, *pointer2;
    printf("Enter The String : ");
    gets(str);
    for (pointer1 = str; *pointer1 != NULL; pointer1++)
        ;
    for (pointer2 = str, pointer1--; pointer1 >= pointer2;)
    {
        if (*pointer1 == *pointer2)
        {
            pointer1--;
            pointer2++;
        }
        else
        {
            break;
        }
    }
    if (pointer2 > pointer1)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
    getch();
    return 0;
}