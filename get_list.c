/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:01:27 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/15 18:48:39 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*create_lst(char **numbers)
{
	int		i;
	t_list	*temp;
	t_list	*temp2;

	i = 0;
	temp2 = NULL;
	while (numbers[i])
	{
		temp = ft_lstnew(ft_atoi_check(numbers[i], numbers));
		if (!temp)
		{
			ft_free(numbers);
			ft_lstclear(&temp);
			exit(-1);
		}
		ft_lstadd_back(&temp2, temp);
		i++;
	}
	return (temp2);
}

static t_list	*order_list(t_list *stack)
{
	t_list	*newlist;
	t_list	*head;
	t_list	*min;
	int		nbr;
	int		position;

	newlist = ft_copy_list(stack);
	head = newlist;
	min = next_min(stack, NULL);
	nbr = 0;
	while (min)
	{
		position = ft_position_lst(stack, min);
		while (--position)
			newlist = newlist->next;
		newlist->content = nbr++;
		newlist = head;
		min = next_min(stack, min);
	}
	ft_lstclear(&stack);
	return (head);
}

t_list	*nbrs_2_lst(char **numbers)
{
	t_list	*first_number;

	first_number = create_lst(numbers);
	first_number = order_list(first_number);
	ft_free(numbers);
	return (first_number);
}

t_list	*get_list(int argc, char **argv)
{
	char	*arr;
	char	*p;
	int		i;
	char	**numbers;

	i = 1;
	arr = NULL;
	while (i < argc)
	{
		p = arr;
		arr = ft_strjoin(arr, argv[i++]);
		free(p);
		if (!arr)
			return (NULL);
		p = arr;
		arr = ft_strjoin(arr, " ");
		free(p);
		if (!arr)
			return (NULL);
	}
	numbers = ft_split(arr, ' ');
	free(arr);
	if (!numbers || !*numbers)
		return (NULL);
	return (check_numbers(numbers));
}
