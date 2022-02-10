/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:27:43 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/09 17:36:08 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}
