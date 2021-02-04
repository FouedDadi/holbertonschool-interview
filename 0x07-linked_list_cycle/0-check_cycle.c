#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - function to check if a linked list has a cycle
 *@list: points to head of the linked list
 * Return: return 0 if there is no cycle and 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
listint_t *p = list;
listint_t *q = list;
while (q && p && p->next)
{
q = q->next;
p = p->next->next;
if (q == p)
return (1);
}
return (0);
}
