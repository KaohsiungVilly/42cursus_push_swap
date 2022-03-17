/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:21:56 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/17 12:14:15 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_sort_short_lst(t_list *stack, t_list *stack_b)
{
	int		size;

	size = ft_lstsize(stack);
	stack_b = NULL;
	if (size == 2)
	{
		if (stack->next->content < stack->content)
			ft_swap(&stack, 'a');
	}
	else if (size == 3)
		ft_sort_3(&stack);
	else if (size == 4)
		ft_sort_4(&stack, &stack_b);
	else if (size == 5)
		ft_sort_5(&stack, &stack_b);
	return (stack);
}

t_list	*ft_sort(t_list *stack, t_list *stack_b)
{
	if (ft_lstsize(stack) <= 5)
		stack = ft_sort_short_lst(stack, stack_b);
	else if (ft_lstsize(stack) <= 150)
		ft_sort100(&stack, &stack_b);
	else
		ft_radix(&stack, &stack_b);
	return (stack);
}
