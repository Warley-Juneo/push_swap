/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:15:50 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/13 19:08:24 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_swap(t_stack **stack_a, t_stack **stack_b, t_stack **stack_c)
{
	int	size_stack;

	(void)stack_b;
	size_stack = ft_stacksize(*stack_a);
	normalize_bubble_sort(stack_c, stack_a);
	if (size_stack <= 3)
		sort_three(stack_a);
	else if (size_stack <= 5)
		sort_five(stack_a, stack_b);
	else
		raddix(stack_a, stack_b);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_c;

	stack_a = NULL;
	stack_b = NULL;
	stack_c = NULL;
	(void)argc;
	if (check_arguments(argv) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_end(&stack_a, argv);
	init_end(&stack_c, argv);
	push_swap(&stack_a, &stack_b, &stack_c);
	del_stacks(&stack_a);
	del_stacks(&stack_c);
	return (0);
}
