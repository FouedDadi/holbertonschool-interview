#include "regex.h"

/**
 * regex_match - compare string and pattern
 * @str: string
 * @pattern: string with special char . or/and *
 * Return: return 1 or 0
 */
int regex_match(char const *str, char const *pattern)
{
if (*str == '\0' && *pattern == '\0')
return (1);
if (*pattern == '.' || *str == *pattern)
return (regex_match(str + 1, pattern + 1));
if (*pattern == '*')
{
if (*str != '\0' && (*str == *pattern || *pattern == '.'))
return ((regex_match(str, pattern + 2) || regex_match(str + 1, pattern)));
}
return (0);
}
