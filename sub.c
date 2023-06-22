#include "monty.h"

/**
 * f_sub - subtracts the top element of the stack from the second top element
 * @head: pointer to the stack head
 * @counter: line number
 * Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int result, count;

	temp = *head;
	for (count = 0; temp != NULL; count++)
		temp = temp->next;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
