#include"palindrome.h"

/**
 * is_palindrome - checks if an unsigned int is palindrom
 * @n: unsigned int
 * Return: returns 1 if num is plaindrome and 0 if not
 */
int is_palindrome(unsigned long n)
{
unsigned long rev = 0, rem, tmp;
tmp = n;
while (tmp != 0)
{
rem = tmp % 10;
rev = rev * 10 + rem;
tmp = tmp / 10;
}
if (rev == n)
return (1);
else
return (0);
}
