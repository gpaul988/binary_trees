#include "binary_trees.h"

/**
 * binary_tree_node - Develop binary tree node.
 * @parent: Directs to  parent of the node to Develop.
 * @value: Value to input in Fresh node.
 *
 * Return: node O/W NULL if error
 * Author: Graham S. Paul (0-binary_tree_node.c)
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}