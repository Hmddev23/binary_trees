#include "binary_trees.h"

/**
  * is_bst - Check if a binary tree is a valid binary search tree.
  *
  * @tree: Pointer to the root node of the tree to check.
  * @lo: Value of the smallest node visited.
  * @hi: Value of the largest node visited.
  *
  * Return: If the tree is a BST return 1, otherwise 0.
  */

int is_bst(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
		{
			return (0);
		}

		return (is_bst(tree->left, lo, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, hi));
	}

	return (1);
}

/**
  * binary_tree_is_bst - Check if a tree is a valid binary search tree.
  *
  * @tree: Pointer to the root node of the tree to check.
  *
  * Return: 1 if tree is a valid BST, otherwise 0.
  */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (is_bst(tree, INT_MIN, INT_MAX));
}
