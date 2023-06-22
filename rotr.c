#include "monty.h"

/**
 * f_rotr -brings the stack around to the base
 * @head: pointer to the stack head
 * @counter: line number
 * Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current;

	current = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = *head;
	current->prev->next = NULL;
	current->prev = NULL;
	(*head)->prev = current;
	(*head) = current;
}
