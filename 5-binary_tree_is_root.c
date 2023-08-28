#include "binary_trees.h"

/* Graham S. Paul (5-binary_tree_is root.c) */

/**
 * binary_tree_is_root - Examines if  node is home of a binary tree.
 * @node: Directs to node to Examine.
 * Return: When the node is a root - 1.
 *         O/W - 0.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}