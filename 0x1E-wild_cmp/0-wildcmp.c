#include "stdio.h"
#include "holberton.h"

/**
 * wildcmp - compare two string with one containing wildcard
 * @s1: string 1 to be compared with s2
 * @s2: string 2 that can contain wildcard
 * Return: 1 or 0
 */
int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
return (1);
if (*s1 == *s2)
return (wildcmp(s1 + 1, s2 + 1));
if (*s2 == '*')
return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
return (0);
}
