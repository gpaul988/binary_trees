#include "binary_trees.h"

/**
 * balance - Calculates stability component of an AVL tree
 * @tree: Tree to be stabilized
 * Author: Graham S. Paul (123-avl_remove.c)
 */

void balance(avl_t **tree)
{
    int b_value;

    if (tree == NULL || *tree == NULL)
        return;
    if ((*tree)->left == NULL && (*tree)->right == NULL)
        return;
    balance(&(*tree)->left);
    balance(&(*tree)->right);
    b_value = binary_tree_balance((const binary_tree_t *)*tree);
    if (b_value > 1)
        *tree = binary_tree_rotate_right((binary_tree_t *)*tree);
    else if (b_value < -1)
        *tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Acquire the following beneficiary
 * with the least node in the right subtree
 * @node: Tree to examined
 * Return: Least worth of the tree
 */
int successor(bst_t *node)
{
    int left = 0;

    if (node == NULL)
    {
        return (0);
    }
    else
    {
        left = successor(node->left);
        if (left == 0)
        {
            return (node->n);
        }
        return (left);
    }
}

/**
 * remove_root - Purpose that detaches a node relying on its children
 * @root: The nodes to be relying
 * Return: 0 it has no children
 * O/W it does
 */
int remove_root(bst_t *root)
{
    int new_value = 0;

    if (!root->left && !root->right)
    {
        if (root->parent->right == root)
            root->parent->right = NULL;
        else
            root->parent->left = NULL;
        free(root);
        return (0);
    }
    else if ((!root->left && root->right) || (!root->right && root->left))
    {
        if (!root->left)
        {
            if (root->parent->right == root)
                root->parent->right = root->right;
            else
                root->parent->left = root->right;
            root->right->parent = root->parent;
        }
        if (!root->right)
        {
            if (root->parent->right == root)
                root->parent->right = root->left;
            else
                root->parent->left = root->left;
            root->left->parent = root->parent;
        }
        free(root);
        return (0);
    }
    else
    {
        new_value = successor(root->right);
        root->n = new_value;
        return (new_value);
    }
}

/**
 * bst_remove - Detach a node from a BST tree
 * @root: The Original of the tree
 * @value: The Node with this Worth to detach
 * Return: Adjusted tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
    int type = 0;

    if (root == NULL)
        return (NULL);
    if (value < root->n)
        bst_remove(root->left, value);
    else if (value > root->n)
        bst_remove(root->right, value);
    else if (value == root->n)
    {
        type = remove_root(root);
        if (type != 0)
            bst_remove(root->right, type);
    }
    else
        return (NULL);
    return (root);
}

/**
 * avl_remove - Detaches a node from an AVL tree
 * @root: Original of the tree
 * @value: The Node with this worth to detach
 * Return: Adjusted tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *root_m = (avl_t *)bst_remove((bst_t *)root, value);

    if (root_m == NULL)
        return (NULL);
    balance(&root_m);
    return (root_m);
}