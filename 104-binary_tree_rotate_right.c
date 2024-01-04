#include "binary_trees.h"

/**
  * binary_tree_rotate_right - Right-rotates a binary tree.
  *
  * @tree: Pointer to the root node of the binary tree.
  *
  * Return: Pointer to the new root node after rotation.
  */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot_right, *tmp_node;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}

	pivot_right = tree->left;
	tmp_node = pivot_right->right;
	pivot_right->right = tree;
	tree->left = tmp_node;

	if (tmp_node != NULL)
	{
		tmp_node->parent = tree;
	}

	tmp_node = tree->parent;
	tree->parent = pivot_right;
	pivot_right->parent = tmp_node;

	if (tmp_node != NULL)
	{
		if (tmp_node->left == tree)
		{
			tmp_node->left = pivot_right;
		}
		else
		{
			tmp_node->right = pivot_right;
		}
	}

	return (pivot_right);
}
