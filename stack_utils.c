#include "push_swap.h"

t_stack	*lst_new(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *) malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	add_back(t_stack **stack, t_stack *node)
{
	t_stack *last;

	if (!stack || !node)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = node;
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next;

	if (!stack)
		return ;
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}
