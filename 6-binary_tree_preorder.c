#include "binary_trees.h"

/**
 * binary_tree_preorder - Moves in a binary tree
 * using pre-order traversal.
 * @tree: Directs to main home node of the tree to traverse.
 * @func: Directs to the purpose to call each node.
 * Author: Graham S. Paul (6-binary_tree_preorder.c)
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}