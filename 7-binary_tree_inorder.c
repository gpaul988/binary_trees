#include "binary_trees.h"

/* Graham S. Paul (7-binary_tree_inorder.c) */

/**
 * binary_tree_inorder - Moves in a binary tree
 * using in-order traversal.
 * @tree: Directs to main home node of the tree to traverse.
 * @func: Directs to the purpose to call each node.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}