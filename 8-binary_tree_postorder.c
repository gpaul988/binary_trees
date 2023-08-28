#include "binary_trees.h"

/* Graham S. Paul (8-binary_tree_postorder.c) */

/**
 * binary_tree_postorder - The Traverses of a binary tree through
 * post-order traversal.
 * @tree: Direct to main home node of the tree to traverse.
 * @func: Direct to purpose to call each node.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}