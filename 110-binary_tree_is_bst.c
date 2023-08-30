#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Examines if binary tree is correct binary search tree.
 * @tree: DIrects root node of the tree to be examined.
 * @lo: worth of  the smallest node visited thus far.
 * @hi: worth of  the largest node visited this far.
 *
 * Return: If tree is valid BST, 1, O/W 0
 * Author: Graham S. Paul (110-binary_tree_is_bst.c)
 */

int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
				is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Examines if a binary tree is correct binary search tree.
 * @tree: Directs root node of the tree to be examined.
 *
 * Return: 1 if tree is correct BST, O/W 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}