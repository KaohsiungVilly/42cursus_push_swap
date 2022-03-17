/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3456.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:02:17 by pvillena          #+#    #+#             */
/*   Updated: 2022/02/16 15:29:03 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if (a < b && a < c && b > c)
	{
		ft_reverse_rotate(stack, 'a');
		ft_swap(stack, 'a');
	}
	else if (a > b && a < c && b < c)
		ft_swap(stack, 'a');
	else if (a < b && a > c && b > c)
		ft_reverse_rotate(stack, 'a');
	else if (a > b && a > c && b < c)
		ft_rotate(stack, 'a');
	else if (a > b && a > c && b > c)
	{
		ft_rotate(stack, 'a');
		ft_swap(stack, 'a');
	}
}

static void	sort_method4(t_list **stack)
{
	while (check_list(*stack) != 0)
	{
		if ((*stack)->content - 1 == (*stack)->next->content)
			ft_swap(stack, 'a');
		else if (ft_lstmin(*stack) == *stack
			&& (*stack)->next == ft_lstmax(*stack))
		{
			ft_swap(stack, 'a');
			ft_rotate(stack, 'a');
		}
		else
			ft_reverse_rotate(stack, 'a');
	}
}

void	ft_sort_4(t_list **stack, t_list **stack_b)
{
	if ((*stack)->next->next == ft_lstmin(*stack))
		sort_method4(stack);
	if (check_list(*stack) == 0)
		return ;
	if (*stack == ft_lstmin(*stack))
		ft_push(stack, stack_b, 'b');
	else if ((*stack)->next == ft_lstmin(*stack))
	{
		ft_rotate(stack, 'a');
		ft_push(stack, stack_b, 'b');
	}
	else if (ft_lstlast(*stack) == ft_lstmin(*stack))
	{
		ft_reverse_rotate(stack, 'a');
		ft_push(stack, stack_b, 'b');
	}
	ft_sort_3(stack);
	ft_push(stack_b, stack, 'a');
}

void	ft_sort_5(t_list **stack, t_list **stack_b)
{
	if (ft_lstmax(*stack) == *stack)
		ft_push(stack, stack_b, 'b');
	else if (ft_position_lst(*stack, ft_lstmin(*stack)) > 3)
	{
		while (*stack != ft_lstmin(*stack))
			ft_reverse_rotate(stack, 'a');
		ft_push(stack, stack_b, 'b');
	}
	else
	{
		while (*stack != ft_lstmin(*stack))
			ft_rotate(stack, 'a');
		ft_push(stack, stack_b, 'b');
	}
	ft_sort_4(stack, stack_b);
	ft_push(stack_b, stack, 'a');
	if (check_list(*stack) != 0)
		ft_rotate(stack, 'a');
}
