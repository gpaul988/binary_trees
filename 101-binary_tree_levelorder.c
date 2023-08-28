#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
			   levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Graham S. Paul (101-binary_tree_levelorder.c) */

/**
 * create_node - Generates fresh levelorder_queue_t node.
 * @node: Binary tree node for fresh node to be held.
 * Return: If error occurs, NULL.
 * O/W, directs to fresh node.
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - AllO/Ws a levelorder_queue_t queue.
 * @head: Directs to the beginning of the queue.
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pint_push - Boots purpose on given binary tree node and
 *             submits its children into a levelorder_queue_t queue.
 * @node: Binary tree node to pull and sumbit.
 * @head: Dual directions to the beginning of the queue.
 * @tail: Dual directions to the end of the queue.
 * @func: Directs to the purpose to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
			   levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - Drop in the beginning of a levelorder_queue_t queue.
 * @head: Dual directions to the beginning of the queue.
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - The Traverses a binary tree using
 *                          level-order traversal.
 * @tree: Directs to the home node of the tree to traverse.
 * @func: Directs to the purpose to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}