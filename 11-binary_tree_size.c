#include "binary_trees.h"

/**
 * binary_tree_size - Calculates size of a binary tree.
 * @tree: Directs to main home node of the tree to
 * calculate the size of.
 * Return: Size of the tree.
 * Author: Graham S. Paul (11-binary_tree_size.c)
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}