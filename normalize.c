/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:35:53 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/13 19:07:04 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	add_index_stack_a(t_stack **stack_a, t_stack **stack_c)
{
	t_stack	*cpy_stack_a;
	t_stack	*cpy_stack_c;
	int		index;

	index = 1;
	cpy_stack_a = *stack_a;
	cpy_stack_c = *stack_c;
	while (cpy_stack_c)
	{
		if (cpy_stack_a->content == (cpy_stack_c)->content)
		{
			cpy_stack_a->index = index++;
			cpy_stack_a = *stack_a;
			cpy_stack_c = (cpy_stack_c)->next;
		}
		else if (cpy_stack_a->next)
			cpy_stack_a = cpy_stack_a->next;
	}
}

int	ordened_stack(t_stack **stack)
{
	t_stack	*cpy_stack;

	cpy_stack = *stack;
	while (cpy_stack && cpy_stack->next)
	{
		if ((cpy_stack->content > cpy_stack->next->content))
			return (0);
		else
			cpy_stack = cpy_stack->next;
	}
	return (1);
}

void	normalize_bubble_sort(t_stack **stack_c, t_stack **stack_a)
{
	t_stack	*cpy_stack_c;
	int		temp;

	cpy_stack_c = *stack_c;
	while (cpy_stack_c && cpy_stack_c->next)
	{
		if (cpy_stack_c->content > cpy_stack_c->next->content)
		{
			temp = cpy_stack_c->content;
			cpy_stack_c->content = cpy_stack_c->next->content;
			cpy_stack_c->next->content = temp;
		}
		cpy_stack_c = cpy_stack_c->next;
	}
	if (ordened_stack(stack_c) == 1)
		add_index_stack_a(stack_a, stack_c);
	else
		normalize_bubble_sort(stack_c, stack_a);
}
