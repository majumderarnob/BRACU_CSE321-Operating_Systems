#include <stdio.h>
int main()
{
    int num1, num2, result;
    printf("Enter two Number: ");
    scanf("%d %d", &num1, &num2);
    if (num1 > num2)
    {
        result = num1 - num2;
        printf("%d - %d = %d", num1, num2, result);
    }
    else if (num1 < num2)
    {
        result = num2 + num1;
        printf("%d + %d = %d", num2, num1, result);
    }
    else
    {
        printf("%d * %d = %d", num1, num2, result);
    }
    return 0;
}