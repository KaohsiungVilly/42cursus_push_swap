/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:47:45 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/15 18:50:47 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_shortest_way(t_list *stack, int midpoint)
{
	t_list	*temp;
	t_list	*temp2;
	int		loop;

	temp = ft_copy_list(stack);
	temp2 = ft_copy_list(stack);
	loop = ft_lstsize(temp);
	while (loop--)
	{
		if (temp->content == midpoint)
		{
			ft_free_temp(&temp, &temp2);
			return ('n');
		}
		else if (temp2->content == midpoint)
		{
			ft_free_temp(&temp, &temp2);
			return ('r');
		}
		ft_rotate(&temp, 'c');
		ft_reverse_rotate(&temp2, 'c');
	}
	ft_free_temp(&temp, &temp2);
	return ('0');
}

char	find_less_than(t_list *stack, int n)
{
	t_list	*temp;
	t_list	*temp_rev;
	size_t	size;

	temp = ft_copy_list(stack);
	temp_rev = ft_copy_list(stack);
	size = ft_lstsize(temp);
	while (size--)
	{
		if (temp->content < n)
		{
			ft_free_temp(&temp, &temp_rev);
			return ('n');
		}
		else if (temp_rev->content < n)
		{
			ft_free_temp(&temp, &temp_rev);
			return ('r');
		}
		ft_rotate(&temp, 'c');
		ft_reverse_rotate(&temp_rev, 'c');
	}
	ft_free_temp(&temp, &temp_rev);
	return ('0');
}

void	ft_find_push(t_list **stack, t_list **stack_b)
{
	char	c;

	while (*stack_b)
	{
		c = ft_shortest_way(*stack_b, ft_lstmax(*stack_b)->content);
		while (c == 'n' && (*stack_b)->content != ft_lstmax(*stack_b)->content)
			ft_rotate(stack_b, 'b');
		while (c == 'r' && (*stack_b)->content != ft_lstmax(*stack_b)->content)
			ft_reverse_rotate(stack_b, 'b');
		ft_push(stack_b, stack, 'a');
	}
}

static void	first_to_stack_b(t_list **stack, t_list **stack_b)
{
	int		midpoint;
	char	check;

	midpoint = (ft_lstsize(*stack) / 2);
	while (ft_lstsize(*stack) > 2)
	{
		while ((*stack)->content < midpoint)
			ft_push(stack, stack_b, 'b');
		check = find_less_than(*stack, midpoint);
		if (check == 'r')
		{
			while ((*stack)->content >= midpoint)
				ft_reverse_rotate(stack, 'a');
		}
		else if (check == 'n')
		{
			while ((*stack)->content >= midpoint)
				ft_rotate(stack, 'a');
		}
		else if (check == '0')
			midpoint = ft_lstsize(*stack) / 2 + ft_lstmin(*stack)->content;
	}
	if ((*stack)->content > (*stack)->next->content)
		ft_swap(stack, 'a');
}

void	ft_sort100(t_list **stack, t_list **stack_b)
{
	first_to_stack_b(stack, stack_b);
	ft_find_push(stack, stack_b);
}
