#include "binary_trees.h"

/**
 * binary_tree_uncle - Discovers the uncle of a node
 * in a binary tree.
 * @node: Directs to node to discover the uncle of.
 * Return: when node is NULL or has no uncle, NULL.
 * O/W, Directs to uncle node.
 * Author: Graham S. Paul (18-binary_tree_uncle.c)
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
		node->parent == NULL ||
		node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}