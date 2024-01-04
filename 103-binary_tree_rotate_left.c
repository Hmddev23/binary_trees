#include "binary_trees.h"

/**
  * binary_tree_rotate_left - Left-rotate a binary tree.
  *
  * @tree: Pointer to the root node of the binary tree.
  *
  * Return: Pointer to the new root node.
  */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot_left, *tmp_node;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	pivot_left = tree->right;
	tmp_node = pivot_left->left;
	pivot_left->left = tree;
	tree->right = tmp_node;

	if (tmp_node != NULL)
	{
		tmp_node->parent = tree;
	}
	tmp_node = tree->parent;
	tree->parent = pivot_left;
	pivot_left->parent = tmp_node;

	if (tmp_node != NULL)
	{
		if (tmp_node->left == tree)
		{
			tmp_node->left = pivot_left;
		}
		else
		{
			tmp_node->right = pivot_left;
		}
	}

	return (pivot_left);
}
