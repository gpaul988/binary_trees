#include "binary_trees.h"

/**
 * binary_tree_nodes - Computes nodes with
 * at least 1 child in a binary tree.
 * @tree: Directs to main home node of the
 * tree to compute the number of nodes.
 * Return: When tree is NULL, purpose must
 * return 0, O/W restore node count.
 * Author: Graham S. Paul (13-binary_tree_nodes.c)
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
