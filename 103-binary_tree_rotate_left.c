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
	binary_tree_t *new_root, *tmp_node;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	new_root = tree->right;
	tmp_node = new_root->left;
	new_root->left = tree;
	tree->right = tmp_node;

	if (tmp_node != NULL)
	{
		tmp_node->parent = tree;
	}
	tmp_node = tree->parent;
	tree->parent = new_root;
	new_root->parent = tmp_node;

	if (tmp_node != NULL)
	{
		if (tmp_node->left == tree)
		{
			tmp_node->left = new_root;
		}
		else
		{
			tmp_node->right = new_root;
		}
	}

	return (new_root);
}
