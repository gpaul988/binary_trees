#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates depth of
 * node in binary tree.
 * @tree: Directs node to Calculate the depth.
 * Return: 0 NULL, O/W depth
 * Author: Graham S. Paul (10-binary_tree_depth.c)
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
