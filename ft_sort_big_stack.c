/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:11:18 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/17 12:14:55 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_temp(t_list **temp, t_list **temp2)
{
	ft_lstclear(temp);
	ft_lstclear(temp2);
}

int	bit_size(int lstsize)
{
	int	nbr_bits;

	nbr_bits = 0;
	while (lstsize > 0)
	{
		lstsize /= 2;
		nbr_bits++;
	}
	return (nbr_bits);
}

void	ft_radix(t_list **stack_a, t_list **stack_b)
{
	int	bit;
	int	i;
	int	size;
	int	nbr_bits;

	size = ft_lstsize(*stack_a);
	bit = 0;
	nbr_bits = bit_size(ft_lstsize(*stack_a));
	while (bit < nbr_bits)
	{
		i = 0;
		while (i++ < size)
		{
			if (((*stack_a)->content >> bit) % 2 == 0)
				ft_push(stack_a, stack_b, 'b');
			else
				ft_rotate(stack_a, 'a');
		}
		while (*stack_b)
			ft_push(stack_b, stack_a, 'a');
		bit++;
	}
}
