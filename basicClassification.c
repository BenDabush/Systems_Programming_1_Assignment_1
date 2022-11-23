#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* will return sqrt of a number*/
int Sqrt(int number)
{
    int sqrt = 1;
    while (sqrt*sqrt <= number)    {sqrt++;}
    return sqrt-1;    
}

/* will return if a number is prime*/
int isPrime(int prime)
{
    if (prime == 1 || prime == 0)
    {
        return FALSE;
    }
    
    int runningIndex = 2;
    int sqrtOfPrime = Sqrt(prime);
    while (runningIndex <= sqrtOfPrime)
    {
        if (prime%runningIndex == 0)
        {
            return FALSE;
        }
        runningIndex+=1;
    }
    return TRUE;
}

/* will return fctorial of a number*/
int Fctorial(int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }

    int fctorial = 2;

    for (int i = 3; i <= number; i++)
    {
        fctorial *= i;
    }
    return fctorial;
}

/*Strong number is a special number whose sum of the factorial of digits is equal to the original
number. For Example: 145 is strong number
1! + 4! + 5! = 145
*/
int isStrong(int number)
{
    int copyNumber = number;
    int digit;
    int strong = 0;
    while (number >= 1)
    {
        digit = number%10;
        number = number/10;
        strong += Fctorial(digit);
    }
    if (copyNumber == strong)
    {
        return TRUE;
    }
    return FALSE;
} 

  
