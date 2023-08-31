#include "binary_trees.h"

/**
 * _sorted_array_to_avl - Assistant purpose for sorted_array_to_avl
 * @array: Insert array
 * @start: Beginning index
 * @end: Conclusion index
 * @parent: Directs to parent node
 * Return: Freshly generated node
 * Author: Graham S. Paul (124-sorted_array_to_avl.c)
 */
avl_t *_sorted_array_to_avl(int *array, int start, int end, avl_t *parent)
{
    avl_t *new;
    int mid;

    if (start > end)
        return (NULL);
    mid = (start + end) / 2;
    new = calloc(1, sizeof(avl_t));
    if (!new)
        return (NULL);
    new->n = array[mid];
    new->parent = parent;
    new->left = _sorted_array_to_avl(array, start, mid - 1, new);
    new->right = _sorted_array_to_avl(array, mid + 1, end, new);
    return (new);
}

/**
 * sorted_array_to_avl - Develops an AVL tree from an array
 * @array: Insert array
 * @size: Area of array
 * Return: DIrects to the original node of the generated AVL tree
 * O/W NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

    if (!array)
        return (NULL);
    return (_sorted_array_to_avl(array, 0, size - 1, NULL));
}