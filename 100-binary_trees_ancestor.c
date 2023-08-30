#include "binary_trees.h"

/**
 * binary_trees_ancestor - Discovers the smallest common
 * ancestor of two nodes.
 * @first: Directs to the first node.
 * @second: Directs to the second node.
 *
 * Return: When there is no common ancestors return NULL,
 * O/W return common ancestor.
 * Author: Graham S. Paul (100-binary_trees_ancestor.c)
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *mom, *pop;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, pop = second->parent;
	if (first == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == second || !pop || (!pop->parent && mom))
		return (binary_trees_ancestor(mom, second));
	return (binary_trees_ancestor(mom, pop));
}
