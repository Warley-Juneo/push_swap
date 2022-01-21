#include "push_swap.h"
#include <stdio.h>

void	sa(t_stack **stack_a)
{
	int	temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->next->content;
		(*stack_a)->next->content = (*stack_a)->content;
		(*stack_a)->content = temp;
	}
}

void	sb(t_stack **stack_b)
{
	int	temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->next->content;
		(*stack_b)->next->content = (*stack_b)->content;
		(*stack_b)->content = temp;

	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack	**stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if ((*stack_b))
	{
		temp = *stack_b;
		if ((*stack_b)->next)
		{
			*stack_b = (*stack_b)->next;
			(*stack_b)->prev = NULL;
		}
		else
			*stack_b = NULL;
		ft_stackadd_front(stack_a, temp);
	}
	printf("pb\n");
}

void	pb(t_stack	**stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if ((*stack_a))
	{
		temp = *stack_a;
		if ((*stack_a)->next)
		{
			*stack_a = (*stack_a)->next;
			(*stack_a)->prev = NULL;
		}
		else
			*stack_a = NULL;
		ft_stackadd_front(stack_b, temp);
	}
	printf("pb\n");
}

void	ra(t_stack	**stack_a)
{
	t_stack	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = ft_stacklast(*stack_a);
		temp->next = *stack_a;
		(*stack_a)->prev = temp;
		*stack_a = (*stack_a)->next;
		temp->next->next = NULL;
	}
	printf("ra\n");
}

void	rb(t_stack	**stack_b)
{
	t_stack	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = ft_stacklast(*stack_b);
		temp->next = *stack_b;
		(*stack_b)->prev = temp;
		*stack_b = (*stack_b)->next;
		temp->next->next = NULL;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack **stack_a)
{
	t_stack *temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = ft_stacklast(*stack_a);
		temp->next = (*stack_a);
		(*stack_a)->prev = temp;
		temp->prev->next = NULL;
		temp->prev = NULL;
		ft_stackadd_front(stack_a, temp);
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack *temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = ft_stacklast(*stack_b);
		temp->next = (*stack_b);
		(*stack_b)->prev = temp;
		temp->prev->next = NULL;
		temp->prev = NULL;
		ft_stackadd_front(stack_b, temp);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
