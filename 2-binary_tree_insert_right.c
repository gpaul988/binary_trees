#include "binary_trees.h"

/**
 * binary_tree_insert_right - Input node as right-child
 * of another in a binary tree.
 * @parent: Directs to node to input the right-child in.
 * @value: Value to save in Fresh node.
 * Return: When parent is NULL or an error occurs - NULL.
 *         O/W - a pointer to the new node.
 * Author: Graham S. Paul (2-binary_tree_insert_right.c)
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