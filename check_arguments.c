/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:35:21 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/13 19:05:48 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_isnumber(char *c)
{
	int	index;
	int	aux;

	index = 0;
	while (c[index])
	{
		if (c[index] == '-' && c[index + 1])
		{
			aux = 1;
			while (c[index + aux])
			{
				if ((c[index + aux] < 48 || c[index + aux] > 57))
					return (1);
				aux++;
			}
			index++;
		}
		else if ((c[index] < 48 || c[index] > 57))
			return (1);
		index++;
	}
	return (0);
}

int	validate_number_aux(char *number)
{
	if ((ft_atoi(number) > 0 && number[0] == '-')
		|| (ft_atoi(number) < 0 && number[0] != '-')
		|| ft_isnumber(number))
		return (0);
	return (1);
}

int	check_arguments(char *argv[])
{
	int		count;
	int		count2;
	int		argv_compar;

	count = 1;
	while (argv[count])
	{
		count2 = count + 1;
		if (validate_number_aux(argv[count]) == 0)
			return (0);
		argv_compar = ft_atoi(argv[count]);
		while (argv[count2])
		{
			if (ft_atoi(argv[count2]) == argv_compar)
				return (0);
			count2++;
		}
		count++;
	}
	return (1);
}
