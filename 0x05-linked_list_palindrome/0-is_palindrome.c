#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * reverse - reverse a linked list
 * @head: pointer to head of list
 */
void reverse(listint_t **head)
{
listint_t *prev = NULL;
listint_t *cur = *head;
listint_t *next = NULL;
while (cur != NULL)
{
next = cur->next;
cur->next = prev;
prev = cur;
cur = next;
}
*head = prev;
}
/**
 * compareLists - compare two linked lists
 * @hf: head of the first linked list
 * @hs: head of the second linked list
 * Return: 1 or 0
 */
int compareLists(listint_t *hf, listint_t *hs)
{
listint_t *tmp1 = hf;
listint_t *tmp2 = hs;
while (tmp1 && tmp2)
{
if (tmp1->n == tmp2->n)
{
tmp1 = tmp1->next;
tmp2 = tmp2->next;
}
else
return (0);
}
if (tmp1 == NULL && tmp2 == NULL)
return (1);
return (0);
}
/**
 * is_palindrome - check if a linked list is palindrome
 * @head: head of the linked list
 * Return: return res which is 1 or 0
 */
int is_palindrome(listint_t **head)
{
listint_t *slow_ptr = *head, *fast_ptr = *head;
listint_t *second_half, *prev_of_slow_ptr = *head;
listint_t *midnode = NULL;
int res = 1;
if (head != NULL)
{
while (fast_ptr != NULL && fast_ptr->next != NULL)
{
fast_ptr = fast_ptr->next->next;
prev_of_slow_ptr = slow_ptr;
slow_ptr = slow_ptr->next;
}
if (fast_ptr != NULL)
{
midnode = slow_ptr;
slow_ptr = slow_ptr->next;
}
second_half = slow_ptr;
prev_of_slow_ptr->next = NULL;
reverse(&second_half);
res = compareLists(*head, second_half);
reverse(&second_half);
if (midnode != NULL)
{
prev_of_slow_ptr->next = midnode;
midnode->next = second_half;
}
else
prev_of_slow_ptr->next = second_half;
}
return (res);
}
