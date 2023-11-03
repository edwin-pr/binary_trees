#include "binary_trees.h"

/**
 * array_to_bst - function builds a BST from an array
 * @array: pointer to the first element to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node || NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree = NULL;

	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}

	return (tree);
}
