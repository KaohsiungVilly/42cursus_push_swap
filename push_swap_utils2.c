/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:00:49 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/17 12:07:36 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_copy_list(t_list *stack)
{
	t_list	*temp;
	t_list	*temp2;
	int		nbr;

	temp = ft_lstnew(stack->content);
	stack = stack->next;
	while (stack)
	{
		nbr = stack->content;
		temp2 = ft_lstnew(nbr);
		ft_lstadd_back(&temp, temp2);
		stack = stack->next;
	}
	return (temp);
}

void	ft_free(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

t_list	*ft_lstmin(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*ft_lstmax(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack)
	{
		if (stack->content > max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
