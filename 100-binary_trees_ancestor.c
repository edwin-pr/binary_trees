#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the LCA || NULL on failure
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *leftLCA, *rightLCA;

	for (leftLCA = first; leftLCA; leftLCA = leftLCA->parent)
		for (rightLCA = second; rightLCA; rightLCA = rightLCA->parent)
			if (leftLCA == rightLCA)
				return ((binary_tree_t *)leftLCA);
	return (NULL);
}
