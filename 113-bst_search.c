#include "binary_trees.h"

/* Graham S. Paul (113-bst_search.c) */

/**
 * bst_search - Foraging for the worth in a binary search tree.
 * @tree: Directs root node of the BST to search.
 * @value: Worth to forage for in the BST.
 *
 * Return: If tree is NULL or the worth is not found, NULL.
 *         Otherwise, Directs node holding the worth.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}