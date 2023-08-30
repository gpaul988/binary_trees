#include "binary_trees.h"


/**
 * binary_tree_delete - Removes binary tree.
 * @tree: Directs to node of the tree to remove.
 * Return: void
 * Author: Graham S. Paul (3-binary_tree_delete.c)
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
