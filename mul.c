#include "monty.h"

/**
 * f_mul - multiplies the top two stack components.
 * @head: head of stack
 * @counter: line_num
 * Return: void
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_length = 0, result;

	current = *head;
	while (current)
	{
		current = current->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	result = current->next->n * current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}
