#include "binary_trees.h"
#include "limits.h"

/* Graham S. Paul (120-binary_tree_is_avl.c) */

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Calculates height of a binary tree.
 * @tree: Directs root node of the tree to Calculate the height.
 *
 * Return: If NULL, function must return 0, else return height.
 */

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper - Examins if the binary tree is a correct AVL tree.
 * @tree: Directs root node of the tree to examine.
 * @lo: Worth of the smallest node visited thus far.
 * @hi: Worth of the largest node visited this far.
 *
 * Return: If tree is a correct AVL tree, 1, otherwise, 0.
 */

int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
				is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Examines if the binary tree is a correct AVL tree.
 * @tree: Directs root node of the tree to Examine.
 *
 * Return: 1 if tree is a correct AVL tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}