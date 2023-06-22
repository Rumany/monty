#include "monty.h"

/**
 * f_rotl - brings the stack around to the top
 * @head: pointer to the stack head
 * @counter: line number
 * Return: void
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *head, *next_node;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	next_node = (*head)->next;
	next_node->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current;
	(*head) = next_node;
}
