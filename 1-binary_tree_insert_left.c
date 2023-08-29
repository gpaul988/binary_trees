#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inputs node as left-child of
 * of another in binary tree.
 * @parent: Directs to node to input the left-child in.
 * @value: Value to save in Fresh node.
 * Return: When parent is NULL or error occurs - NULL.
 *         O/W - directs to fresh node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
