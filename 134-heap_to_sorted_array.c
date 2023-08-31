#include "binary_trees.h"
#include <stdlib.h>
/**
 * heap_to_sorted_array - Change a Binary Highest Heap to a categorized
 * array of number
 * @heap: Directs to the origin node of the heap to change
 * @size: Dircets to save the size of the array
 * Return: Categorized array of number
 * Author: Graham S. Paul (134-heap_to_sorted_array.c)
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    int extract, i = 0;
    size_t heap_size;

    if (!heap)
        return (NULL);
    heap_size = binary_tree_size(heap);
    *size = heap_size;
    array = malloc(heap_size * sizeof(int));
    if (!array)
        return (NULL);
    while (heap)
    {
        extract = heap_extract(&heap);
        array[i] = extract;
        i++;
    }
    return (array);
}