/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:15:50 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/01 15:02:22 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_swap(t_stack **stack_a, t_stack **stack_b, t_stack **stack_c)
{
	int		i;
	int		j;
	int		size;
	int		sizeb;
	int		moviments;

	normalize_bubble_sort(stack_c, stack_a);
	i = 0;
	moviments = 0;
	size = ft_stacksize(*stack_a);
	sizeb = ft_stacksize(*stack_b);
	while (!ordened_stack(stack_a))
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			moviments++;
			j++;
		}
		sizeb = ft_stacksize(*stack_b);
		while ((sizeb--))
		{
			pa(stack_a, stack_b);
			moviments++;
		}
		i++;
		moviments++;
	}
	printf("moviments: %d\n", moviments);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_c;
	t_stack	*temp;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	stack_c = NULL;
	// Verify Arguments;
	i = 1;
	(void)argc;
	while (argv[i])
	{
		temp = ft_stacknew(ft_atoi(argv[i++]));
		ft_stackadd_back(&stack_a, temp);
	}
	i = 1;
	while (argv[i])
	{
		temp = ft_stacknew(ft_atoi(argv[i++]));
		ft_stackadd_back(&stack_c, temp);
	}
	push_swap(&stack_a, &stack_b, &stack_c);
	return (0);
}
