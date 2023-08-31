#include "binary_trees.h"

/**
 * is_full_recursive - Examines if binary tree is full repeatively.
 * @tree: Directs to the main home node of the tree to examine.
 *
 * Return: When tree is not full, 0.
 * O/W, 1.
 * Author: Graham S. Paul (15-binary_tree_is full.c)
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
			(tree->left == NULL && tree->right != NULL) ||
			is_full_recursive(tree->left) == 0 ||
			is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Examines if binary tree is full.
 * @tree: Directs to the main home node of the tree to be examined.
 *
 * Return: WHen tree is NULL or is not full - 0.
 * O/W - 1.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
