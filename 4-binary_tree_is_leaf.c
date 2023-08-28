#include "binary_trees.h"

/* Graham S. Paul (4-binary_tree_is_leaf.c) */

/**
 * binary_tree_is_leaf - Examines if node is leaf of a binary tree.
 * @node: Directs to  node to examine.
 * Return: When node is leaf - 1.
 *         O/W - 0.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}