#include "binary_trees.h"

/**
 * binary_tree_size - Calculate the area of a binary tree
 *
 * @tree: tree root
 * Return: Area of the tree
 * O/W 0 if tree is NULL;
 * Author: Graham S. Paul (130-binary_tree_is_heap.c)
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - Examines if tree is done
 *
 * @tree: Directs to the tree origin
 * @i: The Node index
 * @cnodes: Integer of the nodes
 * Return: 1 if tree is complete
 * O/W 0
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
    if (tree == NULL)
        return (1);

    if (i >= cnodes)
        return (0);

    return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
            tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}

/**
 * binary_tree_is_complete - Echos to tree_is_complete purpose
 *
 * @tree: tree origin
 * Return: 1 if tree is complete
 * O/W 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t cnodes;

    if (tree == NULL)
        return (0);

    cnodes = binary_tree_size(tree);

    return (tree_is_complete(tree, 0, cnodes));
}

/**
 * check_parent - Examines if parent has a Higher worth than its childs
 *
 * @tree: DIrects to the node
 * Return: 1 if parent has a higher worth
 * O/W 0
 */
int check_parent(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (1);

    if (tree->n > tree->parent->n)
        return (0);

    return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - Examines if an input tree is the highest Binary Heap
 *
 * @tree: Directs to the origin of the tree
 * Return: 1 if tree is a Highest Binary Heap
 * O/W 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!binary_tree_is_complete(tree))
        return (0);

    return (check_parent(tree->left) && check_parent(tree->right));
}