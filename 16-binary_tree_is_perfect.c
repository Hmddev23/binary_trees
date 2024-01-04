#include "binary_trees.h"

int perfect_tree(int Level, int Depth, const binary_tree_t *tree);
int get_depth(const binary_tree_t *tree);

/**
  * get_depth - Get the depth of the binary tree.
  *
  * @tree: Pointer to the root node of the tree to check.
  *
  * Return: Tree depth.
  */

int get_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		tree = tree->left;
		depth++;
	}
	return (depth);
}

/**
  * perfect_tree - Check if the tree is perfect.
  *
  * @Level: Number of levels.
  * @Depth: Depth of the tree.
  * @tree: Pointer to the root node of the binary tree to check.
  *
  * Return: 0 || 1.
  */

int perfect_tree(int Level, int Depth, const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	if (!tree->left && !tree->right)
	{
		return (Depth == Level + 1);
	}

	if (!tree->left || !tree->right)
	{
		return (0);
	}

	return (perfect_tree(Level + 1, Depth, tree->left) &&
		perfect_tree(Level + 1, Depth, tree->right));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the binary tree to check.
 *
 * Return: State of the binary tree.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;
	int height = 0;

	depth = get_depth(tree);
	return (perfect_tree(height, depth, tree));
}
