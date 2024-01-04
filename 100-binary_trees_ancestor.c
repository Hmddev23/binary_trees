#include "binary_trees.h"

/**
  * binary_trees_ancestor - Find the lowest common ancestor of two nodes.
  *
  * @first: Pointer to the first node.
  * @second: Pointer to the second node.
  *
  * Return: common ancestors.
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	binary_tree_t *first_d, *second_d;

	if (!first || !second)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	first_d = first->parent, second_d = second->parent;
	if (first == second_d || !first_d || (!first_d->parent && second_d))
	{
		return (binary_trees_ancestor(first, second_d));
	}
	else if (first_d == second || !second_d || (!second_d->parent && first_d))
	{
		return (binary_trees_ancestor(first_d, second));
	}

	return (binary_trees_ancestor(first_d, second_d));
}
