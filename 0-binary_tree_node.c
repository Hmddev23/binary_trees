#include "binary_trees.h"

/**
  * binary_tree_node - Create a new binary tree node.
  *
  * @parent: Pointer to the parent node.
  * @value: Value to be assigned to the new node.
  *
  * Return: If successful, a pointer to the new node; otherwise, NULL.
  */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->n = value;

	return (new);
}
