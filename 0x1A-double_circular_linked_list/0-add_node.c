#include "list.h"

/**
 * ptr_node - create a new node with str as data
 * @str: string to be copied into the new node
 * Return: return a pointer to ptr new node
 */
List *ptr_node(char *str)
{
struct List *ptr = NULL;
ptr = malloc(sizeof(List));
if (!ptr)
return (NULL);
ptr->str = strdup(str);
if (!ptr->str)
return (NULL);
ptr->next = NULL;
ptr->prev = NULL;
return (ptr);
}

/**
 * add_node_end - add a new node at the end of circular doubly linked list
 * @list: list to be modified
 * @str: string to be copied into the new node
 * Return: return a pointer to ptr new node
 */
List *add_node_end(List **list, char *str)
{
struct List *temp, *ptr;
ptr = ptr_node(str);
if (ptr == NULL)
{
return (NULL);
}
else
{
ptr->str = str;
if ((*list) == NULL)
{
(*list) = ptr;
ptr->next = (*list);
ptr->prev = (*list);
}
else
{
temp = (*list);
while (temp->next != (*list))
{
temp = temp->next;
}
temp->next = ptr;
ptr->prev = temp;
(*list)->prev = ptr;
ptr->next = (*list);
}
}
return (ptr);
}

/**
 * add_node_begin - add a new node at the beginning of circular D-L-L
 * @list: list to be modified
 * @str: string to be copied into the new node
 * Return: return a pointer to ptr new node
 */
List *add_node_begin(List **list, char *str)
{
struct List *temp, *ptr;
ptr = ptr_node(str);
if (ptr == NULL)
{
return (NULL);
}
else
{
ptr->str = str;
if ((*list) == NULL)
{
(*list) = ptr;
ptr->next = (*list);
ptr->prev = (*list);
}
else
{
temp = (*list);
while (temp->next != (*list))
{
temp = temp->next;
}
temp->next = ptr;
ptr->prev = temp;
(*list)->prev = ptr;
ptr->next = (*list);
*list = ptr;
}
}
return (ptr);
}
