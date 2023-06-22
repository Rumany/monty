#include "monty.h"

/**
 * addnode - adds a new node to the head of the stack.
 * @head: pointer to the head of the stack
 * @new_value: new value to be stored in the node
 * Return: void
 */
void addnode(stack_t **head, int new_value)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (current)
		current->prev = new_node;
	new_node->n = new_value;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
