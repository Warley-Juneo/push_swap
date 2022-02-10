/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:39:58 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/09 20:58:45 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf("sa\n");
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
	printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss\n")
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
	printf("pa\n");
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
