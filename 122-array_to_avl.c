#include "binary_trees.h"
/* Graham S. Paul (122-array_to_avl.c) *

/**
 * array_to_avl - Develoops AVL tree from an array.
 * @array: Directs to first element of the array to be changed.
 * @size: Number of elements in @array.
 *
 * Return: Directs to root node of the Generated AVL, or NULL upon failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}