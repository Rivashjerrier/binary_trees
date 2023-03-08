#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 *         If no common ancestor was found, return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *ancestor;
	size_t depth1, depth2;

	if (first == NULL || second == NULL)
		return (NULL);

	depth1 = binary_tree_depth(first);
	depth2 = binary_tree_depth(second);

	while (depth1 > depth2)
	{
		first = first->parent;
		depth1--;
	}

	while (depth2 > depth1)
	{
		second = second->parent;
		depth2--;
	}

	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	ancestor = (first && second) ? (binary_tree_t *)first : NULL;
	return (ancestor);
}

/**
 * binary_tree_depth - Function gives the depth of @tree node.
 * @tree: Pointer to the node to measure the depth
 * Description: Recursively tunnel upwards to get to the root node and sum all
 * return values of returned stacks.
 *
 * Return: Depth of certain node, 0 otherwise.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || !tree->parent)
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}
