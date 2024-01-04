#include "binary_trees.h"

/**
  * binary_tree_insert_right - Insert a new node as a right child.
  *
  * @parent: Pointer to the node where the right child will be inserted.
  * @value: Value to be stored in the new node.
  *
  * Return: Pointer to the newly created node.
  */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
	new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
