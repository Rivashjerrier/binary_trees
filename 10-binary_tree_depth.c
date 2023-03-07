#include "binary_trees.h"

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
