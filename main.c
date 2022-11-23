#include <stdio.h>
#include "NumClass.h"

int main()
{
    int num1, num2;
    printf("Please enter first number: ");
    scanf("%d", &num1);
    printf("Please enter second number: ");
    scanf("%d", &num2);

    for (int i = num1; i <= num2; i++)
    {
        if (isPrime(i)==1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

   for (int i = num1; i < num2; i++)
    {
        if (isArmstrong(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

   for (int i = num1; i < num2; i++)
    {
        if (isStrong(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

       for (int i = num1; i < num2; i++)
    {
        if (isPalindrome(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}