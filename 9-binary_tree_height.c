#include "binary_trees.h"

/**
 * binary_tree_height - Calculates height of binary tree.
 *
 * @tree: Directs to main home node of the
 * tree to calculates the height.
 * Return: When tree is NULL, purpose  must restore 0, O/W restore height.
 * Author: Graham S. Paul (9-binary_tree_height.c)
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}