#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * new_node - create a new node that contains the number
 * @number: number to be inserted in the new node
 * Return: return the adress of the node new
 */
listint_t *new_node(int number)
{
listint_t *new;
new = (struct listint_s *) malloc(sizeof(struct listint_s));
if (new == NULL)
{
return (NULL);
}
new->n = number;
new->next = NULL;
return (new);
}
/**
 * insert_node - function to print list after insertion
 * @head: head
 * @number: the data of the node new
 * Return: return the adress of the node new
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new, *cur;
new = new_node(number);
cur = *head;
while (cur->next != NULL && new->n > cur->next->n)
cur = cur->next;
new->next = cur->next;
cur->next = new;
return (new);
}
