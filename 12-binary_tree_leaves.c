#include "binary_trees.h"

/**
 * binary_tree_leaves - Computes leaves in a binary tree.
 * @tree: Directs to the main home node of the tree
 * to compute the leaves of.
 * Return: Number of leaves in the tree.
 * Author: Grahama S. Paul (12-binary_tree_leaves.c)
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
