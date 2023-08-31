#include "binary_trees.h"

/**
 * array_to_heap - Develops the highest Binary Heap tree from an array
 * @array: Insert array
 * @size: Area of array
 * Return: Directs to the origin node of the generated Binary Heap,
 * O/W NULL on failure
 * Author: Graham S. Paul (132-array_to_heap.c)
 */
heap_t *array_to_heap(int *array, size_t size)
{
    size_t i = 0;
    bst_t *root = NULL;

    if (!array)
        return (NULL);
    while (i < size)
    {
        heap_insert(&root, array[i]);
        i++;
    }
    return (root);
}