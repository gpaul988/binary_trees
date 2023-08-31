#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Restores minimum value of a binary search tree.
 * @root: Directs root node of the BST to search.
 *
 * Return: Minimum value in @tree.
 * Author: Graham S. Paul (114-bst_remove.c)
 */

bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Removes node from a binary search tree.
 * @root: Directs root node of the BST.
 * @node: Directs node to delete from the BST.
 *
 * Return: Directs fresh root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* Not children or right-child */

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child */

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* 2 children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Deletes node from a binary search tree contineously.
 * @root: Directs root node of the BST to delete node from.
 * @node: Directs current node in the BST.
 * @value: Worth to delete from the BST.
 *
 * Return: Directs root node after deletion.
 */

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Deletes  node from a binary search tree.
 * @root: Directs root node of the BST to delete node from.
 * @value: Worth delete in the BST.
 *
 * Return: Directs fresh root node after removal.
 *
 * Description: If node to remove has two children, it
 *              is changed with its first in-order successor.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
