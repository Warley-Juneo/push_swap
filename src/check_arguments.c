/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:35:21 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/02/09 18:14:53 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_arguments(char *argv[])
{
	int		flag;
	int		count;
	int		count2;
	int		argv_compar;

	count = 1;
	count2 = 1;
	flag = 0;
	while (argv[count])
	{
		argv_compar = ft_atoi(argv[count]);
		while (argv[count2])
		{
			if (argv_compar == ft_atoi(argv[count2++]))
			{
				flag = flag + 1;
				if (flag > 1)
					return (0);
			}
		}
		count2 = 1;
		count++;
		flag = 0;
	}
	return (1);
}
