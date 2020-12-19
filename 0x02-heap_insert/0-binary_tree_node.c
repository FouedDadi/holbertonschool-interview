#include "binary_trees.h"
/**
* binary_tree_node - function that creates a binary tree node
* @parent: parent of the created binary tree node
* @value: value stored in the new binary tree node
* Return: return the new binary tree node or NULL if the new node is null
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new;
new = (struct binary_tree_s *) malloc(sizeof(struct binary_tree_s));
if (new == NULL)
return (NULL);
new->n = value;
new->left = NULL;
new->right = NULL;
new->parent = parent;
return (new);
}
