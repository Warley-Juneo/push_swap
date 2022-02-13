/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:36:24 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/13 19:06:45 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_end(t_stack **stack, char	*argv[])
{
	int		i;
	t_stack	*temp;

	i = 1;
	while (argv[i])
	{
		temp = ft_stacknew(ft_atoi(argv[i++]));
		ft_stackadd_back(stack, temp);
	}
}

void	del_stacks(t_stack **stack)
{
	t_stack		*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	stack = NULL;
}
