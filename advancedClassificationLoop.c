#include <stdio.h>

int powToNumber(int x, int y)
{
    int sum = x;
    for (int i = 1; i < y; i++)
    {
        sum *=x;
    }
    return sum;
}


/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int number)
{
    int copyNumber = number;
    int longth = 0;
    int decimal = 1;
    int sum = 0;
    while (0<copyNumber)
    {
        copyNumber = copyNumber/10;
        longth+=1;
    }

    copyNumber = number;
    while (0<copyNumber)
    {
        decimal = copyNumber%10;
        sum += powToNumber(decimal, longth);
        copyNumber = copyNumber/10;
    }
    
    if (sum == number)
    {
        return 1;
    }
    return 0;    
}

/* will return if a number is a palindrome */
int isPalindrome(int number)
{
    int reversdNumber = 0;
    int copyNumber = number;

    while (0<copyNumber)
    {
        reversdNumber = reversdNumber*10 + copyNumber%10;
        copyNumber = copyNumber/10;
    }
    if (reversdNumber == number)
    {
        return 1;
    }
    return 0;
}

