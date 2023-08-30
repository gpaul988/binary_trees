#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Anti-clockwise rotation of binary tree.
 * @tree: Directs root node of the tree to rotate.
 *
 * Return: Directs fresh root node after rotation.
 * Author: Grhaam S. Paul (103-binary_tree_rotate_left.c)
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	tmp = pivot->left;
	pivot->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}

	return (pivot);
}