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
listint_t *new, *cur, *tmp;
new = new_node(number);
cur = *head;
if (*head == NULL || (*head)->n > number)
{
new->next = *head;
*head = new;
}
while (cur->next != NULL && cur->next->n <= number)
cur = cur->next;
tmp = cur->next;
cur->next = new;
new->next = tmp;
return (new);
}
