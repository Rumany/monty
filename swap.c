#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack
 * @head: pointer to the stack head
 * @counter: line number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int length = 0, value;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = value;
}
