#include <stdio.h>

int powToNumber(int x, int y)
{
    if (y == 1)
    {
        return x;
    }
    return x*powToNumber(x, (y-1));
}

int length(int number, int count)
{
    if (number == 0)
    {
        return count;
    }
    return length(number/10, count+=1);
}

int isArmstrongRecursive(int number, int len)
{
    if (number == 0)
    {
        return 0;
    }
    return powToNumber(number%10, len)+isArmstrongRecursive(number/10, len);
}

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int number)
{
    int len = length(number, 0);
    int armstrong = isArmstrongRecursive(number, len);
    if (armstrong == number)
    {
        return 1;
    }
    return 0;
}

int reversRecursive(int reversdNumber, int number)
{
    if (number == 0)
    {
        return reversdNumber;
    }
    reversdNumber = reversdNumber*10 + number%10;
    number = number/10;
    return reversRecursive(reversdNumber, number);
}

/* will return if a number is a palindrome */
int isPalindrome(int number)
{
    int reversdNumber = reversRecursive(0, number);
    if (reversdNumber == number)
    {
        return 1;
    }
    return 0;
}
  