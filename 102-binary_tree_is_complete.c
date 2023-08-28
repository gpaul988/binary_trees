#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		  levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/* Graham S. Paul (102-binary_tree_is complete.c) */

/**
 * create_node - Generates fresh levelorder_queue_t node.
 * @node: Binary tree node for Fresh node to held.
 *
 * Return: If error occurs, NULL.
 *			O/W directs to Fresh node.
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
 * @head: Directs to the beginning of queue.
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
 * push - Propels node to the end of a levelorder_queue_t queue.
 * @node: Binary tree node to Pull and submitted.
 * @head: Dual directions to the beginning of queue.
 * @tail: Dual directions to the end of the queue.
 *
 * Description: On malloc failure, exit with status code of 1.
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		  levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Drop in the beginning of levelorder_queue_t queue.
 * @head: Dual direction to the beginnig of queue.
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Examines if binary tree is done.
 * @tree: Directs to the root node of the tree to traverse.
 *
 * Return: If tree is NULL or incomplete, 0.
 *         O/W, 1.
 *
 * Description: on malloc failure, exit with status code of 1.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
