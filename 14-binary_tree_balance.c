#include "binary_trees.h"

/* Graham S. Paul (14-binary_tree_balance.c) */

/**
 * binary_tree_balance - Calculates the balance
 * component of a binary tree.
 * @tree: Directs to the main home node of the
 * tree to Calculate the balance component.
 * Return: When tree is NULL, return 0,
 * O/W restore balance component.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) -
				binary_tree_height(tree->right));
	}

	return (0);
}

/**
 * binary_tree_height - Calculates the height of a binary tree.
 * @tree: Directs to the main home node of the
 * tree to Calculate the height.
 * Return: When tree is NULL, your purpose must
 * return 0, O/W restotre height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}