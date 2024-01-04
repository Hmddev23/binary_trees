#include "binary_trees.h"

/**
  * binary_tree_is_leaf - Check if a node is a leaf
  *
  * @node: pointer to the node to check
  *
  * Return: 1 if node is leaf, otherwise 0.
  */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
	{
		return (1);
	}

	return (0);
}

/**
  * binary_tree_height - Measure the binary tree height.
  *
  * @tree: Pointer to the root node of the binary tree.
  *
  * Return: Height of the binary tree.
  */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
	{
		return (0);
	}

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
	{
		return (1 + left);
	}

	return (1 + right);
}

/**
  * binary_tree_is_perfect - Check if a binary tree is perfect.
  *
  * @tree: Pointer to the root node of the tree.
  *
  * Return: 1 if perfect, otherwise 0.
  */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (1);
	left = tree->left;
	right = tree->right;
	if (binary_tree_is_leaf(tree))
	{
		return (1);
	}

	if (left == NULL || right == NULL)
	{
		return (0);
	}

	if (binary_tree_height(left) == binary_tree_height(right))
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_perfect(right))
		{
			return (1);
		}
	}

	return (0);
}

/**
  * binary_tree_is_complete - Check if a binary tree is complete.
  *
  * @tree: Pointer to the root node of the tree.
  *
  * Return: State of the tree.
  */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *left, *right;

	if (tree == NULL)
	{
		return (0);
	}
	if (binary_tree_is_leaf(tree))
	{
		return (1);
	}

	left = tree->left;
	right = tree->right;
	l_height = binary_tree_height(left);
	r_height = binary_tree_height(right);

	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_complete(right))
		{
			return (1);
		}
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(left) && binary_tree_is_perfect(right))
		{
			return (1);
		}
	}

	return (0);
}
