/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:15:50 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/01/21 20:46:30 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_my_list(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cpy_stack_a;
	t_stack *cpy_stack_b;

	cpy_stack_a = *stack_a;
	cpy_stack_b = *stack_b;
	while(cpy_stack_a)
	{
		printf("A: content = %d | index = %d\n", cpy_stack_a->content, cpy_stack_a->index);
		cpy_stack_a = cpy_stack_a->next;
	}
	printf("-*-*-*-*-*-*-*-*-*-*\n");
	while(cpy_stack_b)
	{
		printf("b: content = %d | index = %d\n", cpy_stack_b->content, cpy_stack_b->index);
		cpy_stack_b = cpy_stack_b->next;
	}
}

int	push_swap(t_stack **stack_a, t_stack **stack_b, t_stack **stack_c)
{
	int		i;
	int		j;
	int		n;
	int		size;
	int		sizeb;


	normalize_bubble_sort(stack_c, stack_a);
	i = 0;
	size = ft_stacksize(*stack_a);
	sizeb = ft_stacksize(*stack_b);

	while(!ordened_stack(stack_a))
	{
		j = 0;
		while (j < size)
		{
			n = (*stack_a)->index;
			if ((n >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		sizeb = ft_stacksize(*stack_b);
		while ((sizeb--))
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *stack_c;
	t_stack	*temp;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	stack_c = NULL;
	// Verify Arguments;
	i = 1;
	while(argv[i])
	{
		temp = ft_stacknew(ft_atoi(argv[i++]));
		ft_stackadd_back(&stack_a, temp);
	}
	i = 1;
	while(argv[i])
	{
		temp = ft_stacknew(ft_atoi(argv[i++]));
		ft_stackadd_back(&stack_c, temp);
	}
	push_swap(&stack_a, &stack_b, &stack_c);
	return (0);
}
