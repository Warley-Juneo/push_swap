/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:15:52 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/01/21 21:44:58 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

t_stack	*ft_stacknew(int content);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *lst);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack	**stack_a, t_stack **stack_b);
void	pb(t_stack	**stack_a, t_stack **stack_b);
void	ra(t_stack	**stack_a);
void	rb(t_stack	**stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ordened_stack(t_stack **stack);
void	normalize_bubble_sort(t_stack **stack_c, t_stack **stack_a);
void	add_index_stack_a(t_stack **stack_a, t_stack **stack_c);
#endif
