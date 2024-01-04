#include "binary_trees.h"

/**
  * binary_tree_height - Measure the height of a binary tree.
  *
  * @tree: Pointer to the root node of a binary tree.
  *
  * Return: If tree is NULL, your function must return 0, else return height.
  */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0;
		size_t right = 0;

		left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((left > right) ? left : right);
	}
	return (0);
}
