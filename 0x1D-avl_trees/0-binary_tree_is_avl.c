#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * getMax - check max of two numbers a and b
 * @a: Int a
 * @b: Int b
 * Return: a if a > b, b if not
 */
int getMax(int a, int b)
{
if (a >= b)
return (a);
else
return (b);
}

/**
 * getHeight - get the height of binary tree
 * @tree: pointer to the root node of the tree
 * Return: return the height of a binary tree
 */
int getHeight(const binary_tree_t *tree)
{
int leftHeight, rightHeight;
if (tree == NULL)
return (0);
leftHeight = getHeight(tree->left);
rightHeight = getHeight(tree->right);
return (getMax(leftHeight, rightHeight) + 1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree
 * Return: return 1 if binary tree is valid AVL tree or 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
int leftHeight, rightHeight;
if (tree == NULL)
return (0);
leftHeight = getHeight(tree->left);
rightHeight = getHeight(tree->right);
if (abs(leftHeight - rightHeight) <= 1 &&
binary_tree_is_avl(tree->right) &&
binary_tree_is_avl(tree->left))
return (1);
else
return (0);
}
