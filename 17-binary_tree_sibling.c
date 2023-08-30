#include "binary_trees.h"

/**
 * binary_tree_sibling - DIscovers the sibling of a
 * node in a binary tree.
 * @node: Directs to node to discover the sibling of.
 * Return: WHen node is NULL or no sibling - NULL.
 * O/W - Directs to sibling.
 * Author: Graham S. Paul (17-binary_tree_siblings.c)
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
