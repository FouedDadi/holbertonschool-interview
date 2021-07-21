#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * isBSTUtil - utility function needed for isBST
 * @tree: pointer to the root node of the tree
 * @min: Int min
 * @max: Int max
 * Return: 1 if tree is BST tree, 0 if not
 */
int isBSTUtil(const binary_tree_t *tree, int min, int max)
{
if (tree == NULL)
return (1);
if (tree->n < min || tree->n > max)
return (0);
return (isBSTUtil(tree->left, min, tree->n - 1) &&
isBSTUtil(tree->right, tree->n + 1, max));
}

/**
 * isBST - check if binary tree is BST tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if tree is BST tree, 0 if not
 */
int isBST(const binary_tree_t *tree)
{
return (isBSTUtil(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_bst - check if binary tree is BST tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if tree is BST tree, 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (tree ? isBST(tree) : 0);
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
if (leftHeight >= rightHeight)
return (leftHeight + 1);
else
return (rightHeight + 1);
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
return (1);
leftHeight = getHeight(tree->left);
rightHeight = getHeight(tree->right);
if (abs(leftHeight - rightHeight) <= 1 &&
binary_tree_is_avl(tree->right) &&
binary_tree_is_avl(tree->left) && binary_tree_is_bst(tree))
return (1);
else
return (0);
}
