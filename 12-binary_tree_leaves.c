#include "binary_trees.h"

/**
  * binary_tree_leaves - Count the leaves in a binary tree.
  *
  * @tree: Pointer to the root node of the tree.
  *
  * Return: Number of leaves in the tree.
  */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leave = 0;

	if (tree)
	{
		leave += (!tree->left && !tree->right) ? 1 : 0;
		leave += binary_tree_leaves(tree->left);
		leave += binary_tree_leaves(tree->right);
	}

	return (leave);
}
