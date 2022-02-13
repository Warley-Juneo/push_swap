/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:39:04 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/10 22:21:35 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	t_stack	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = ft_stacklast(*stack_a);
		temp->next = (*stack_a);
		(*stack_a)->prev = temp;
		temp->prev->next = NULL;
		temp->prev = NULL;
		ft_stackadd_front(stack_a, temp);
	}
	printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack	*temp;

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
