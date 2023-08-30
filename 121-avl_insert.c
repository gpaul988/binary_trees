#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
							avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Calculate height of a binary tree.
 * @tree: Directs root node of the tree to calculate the height.
 *
 * Return: If NULL, function must return 0, else return height.
 * Author: Graham S. Paul (121-avl_insert.c)
 */

size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Calculates the offset factor of a binary tree.
 * @tree: Directs root node of the tree to calculate the offset factore.
 *
 * Return: If NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Input value into an AVL tree recursively.
 * @tree: Dual direction to root node of the AVL tree to insert into.
 * @parent: Parent node of the current working node.
 * @new: Dual direction to save the new node.
 * @value: Input value into the AVL tree.
 *
 * Return: Directs new root after insertion, or NULL on failure.
 */

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
							avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Input a value into an AVL tree.
 * @tree: Dual direction to root node of the AVL tree to input into.
 * @value: Input value into the AVL tree.
 *
 * Return: inputs directs to node, or NULL on failure.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
