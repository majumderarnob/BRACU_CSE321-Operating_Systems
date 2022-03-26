#include <stdio.h>

void perfectNumberChecker(int num1, int num2)

{
    int i = 0, total = 0;
    while (num1 <= num2)
    {
        total = 0;
        for (i = 1; i < num1; i++)
        {
            if (num1 % i == 0)
            {
                total = total + i;
            }
        }
        if (total == num1)
        {
            printf("Perfect number between this interval %d \n", num1);
        }
        num1++;
    }
}

int main()
{

    int i, j;
    printf("Enter lower limit: ");
    scanf("%d", &i);
    printf("Enter higher limit: ");
    scanf("%d", &j);
    perfectNumberChecker(i, j);
    return 0;
}