/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:21:31 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/14 18:27:36 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char stackc)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack;
	temp = temp->next;
	temp2 = temp;
	temp2 = temp2->next;
	(*stack)->next = temp2;
	temp->next = *stack;
	*stack = temp;
	if (stackc != 'c')
		ft_printf("s%c\n", stackc);
}

void	ft_push(t_list **from, t_list **to, char toc)
{
	t_list	*temp;

	temp = ft_lstnew((*from)->content);
	ft_lstadd_front(to, temp);
	temp = *from;
	*from = (*from)->next;
	free(temp);
	ft_printf("p%c\n", toc);
}

void	ft_rotate(t_list **stack, char stackc)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	if (stackc != 'c')
		ft_printf("r%c\n", stackc);
}

void	ft_reverse_rotate(t_list **stack, char stackc)
{
	t_list	*temp;
	t_list	*last;

	temp = *stack;
	last = ft_lstlast(*stack);
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack, last);
	if (stackc != 'c')
		ft_printf("rr%c\n", stackc);
}
