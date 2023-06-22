#include "monty.h"

/**
 * f_mod - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int length = 0, result;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		length++;
	}
	
	if (length < 2)
	{
		fprintf(stderr, "L%d: unable to perform modulo operation, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = ptr->next->n % ptr->n;
	ptr->next->n = result;
	*head = ptr->next;
	free(ptr);
}
