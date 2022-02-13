/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:27:43 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/13 19:09:54 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(t_stack **stack_a, int index)
{
	int		count;
	t_stack	*stack_temp;

	count = 1;
	stack_temp = *stack_a;
	while (stack_temp->index != index)
	{
		stack_temp = stack_temp->next;
		count++;
	}
	return (count);
}

void	send_top(t_stack **stack_a, int index)
{
	int	size_stack;
	int	tam;

	size_stack = ft_stacksize(*stack_a) / 2;
	tam = find_index(stack_a, index);
	while ((*stack_a)->index != index)
	{
		if (tam <= size_stack)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (ft_stacksize(*stack_a) == 2 && !ordened_stack(stack_a))
		sa(stack_a);
	while (!ordened_stack(stack_a))
	{
		a = (*stack_a)->index;
		b = (*stack_a)->next->index;
		c = (*stack_a)->next->next->index;
		if ((a > b && c > a && c > b) || (a > b && a > c && b > c)
			|| (a < b && b > c && a < c))
			sa(stack_a);
		else if (a > b && a > c)
			ra(stack_a);
		else if (a < b && b > c)
			rra(stack_a);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (!ordened_stack(stack_a))
	{
		while (ft_stacksize(*stack_a) != 3 && ft_stacksize(*stack_a) != 2)
		{
			send_top(stack_a, 1);
			pb(stack_a, stack_b);
			send_top(stack_a, 2);
			pb(stack_a, stack_b);
		}
		sort_three(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	raddix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);
	while (!ordened_stack(stack_a))
	{
		j = 0;
		while (j < size_a)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		size_b = ft_stacksize(*stack_b);
		while ((size_b--))
			pa(stack_a, stack_b);
		i++;
	}
}
