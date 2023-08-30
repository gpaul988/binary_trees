#include "binary_trees.h"

/**
 * is_leaf - Examins if a node is a leaf of a binary tree.
 * @node: Directs node to be examined.
 *
 * Return: When node is a leaf, 1, O/W, 0.
 * Author: Graham S. Paul (16-binary_tree_is perfect)
 */

unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Restores depth of a given
 * node in a binary tree.
 * @tree: Directs node to calculate the depth of.
 *
 * Return: Depth of node.
 */

size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Restores a leaf of a binary tree.
 * @tree: Directs to main home node of the tree to search a leaf in.
 *
 * Return: Directs to the first encountered leaf.
 */

const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Examines if binary tree is perfect contineously.
 * @tree: Directs to the main home node of the tree to examine.
 * @leaf_depth: Depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return:When the tree is perfect, 1, O/W 0.
 */

int is_perfect_recursive(const binary_tree_t *tree,
						 size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Examines if binary tree is perfect.
 * @tree: Directs to the main home node of the tree to examine.
 *
 * Return: When tree is NULL or not perfect, 0.
 *         O/W, 1.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}