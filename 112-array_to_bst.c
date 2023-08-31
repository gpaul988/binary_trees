#include "binary_trees.h"

/**
 * array_to_bst - Generates binary search tree from an array.
 * @array: Directs first element of the array to be changed.
 * @size: Number of elements in @array.
 *
 * Return: Directs root node of genrated BST, or NULL upon failure.
 * Author: Graham S. Paul (112-array_to_bst.c)
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
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
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
