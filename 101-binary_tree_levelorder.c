#include "binary_trees.h"

/**
  * binary_tree_height - Measure the height of a binary tree
  *
  * @tree: Pointer to the root node of the binary tree.
  *
  * Return: Height of the tree.
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
  * binary_tree_level - perform a function on a specific level of a tree.
  *
  * @tree: Pointer to the root of the tree.
  * @l: Level of the binary tree.
  * @func: A function to perform.
  *
  * Return: Nothing.
  */

void binary_tree_level(const binary_tree_t *tree, size_t l, void (*func)(int))
{
	if (tree == NULL)
	{
		return;
	}

	if (l == 1)
	{
		func(tree->n);
	}
	else if (l > 1)
	{
		binary_tree_level(tree->left, l - 1, func);
		binary_tree_level(tree->right, l - 1, func);
	}
}

/**
  * binary_tree_levelorder - traverses a binary tree in level-order traversal.
  *
  * @tree: Pointer to the root node of the binary tree.
  * @func: Pointer to a function to call for each node.
  *
  * Return: Nothing.
  */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, idx;

	if (tree == NULL || func == NULL)
	{
		return;
	}

	height = binary_tree_height(tree);
	for (idx = 1; idx <= height; idx++)
	{
		binary_tree_level(tree, idx, func);
	}
}
