/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:20:23 by pvillena          #+#    #+#             */
/*   Updated: 2022/02/16 15:29:49 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_check(const char *str, char **numbers)
{
	long int	ans;
	int			sign;

	ans = 0;
	sign = 1;
	if (*str == 45)
	{
		sign *= -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str > 47 && *str < 58)
	{
		ans = ans * 10 + (*str - 48);
		str++;
	}
	if (ans * sign > 2147483647 || ans * sign < -2147483648)
	{
		ft_free(numbers);
		ft_printf("Error");
		exit(1);
	}
	return ((int)(ans * sign));
}

int	ft_isnumber(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s++) == 0)
			return (0);
	}
	return (1);
}

int	ft_position_lst(t_list *stack, t_list *element)
{
	int	position;

	position = 1;
	while (stack)
	{
		if (stack == element)
			return (position);
		position++;
		stack = stack->next;
	}
	return (0);
}

int	check_list(t_list *stack)
{
	t_list	*temp;

	temp = stack->next;
	while (temp)
	{
		if (temp->content < stack->content)
			return (1);
		temp = temp->next;
		stack = stack->next;
	}
	return (0);
}

t_list	*next_min(t_list *stack, t_list *last_min)
{
	t_list	*min;

	min = ft_lstmax(stack);
	if (!last_min)
		return (ft_lstmin(stack));
	else if (last_min->content == min->content)
		return (NULL);
	while (stack)
	{
		if (stack->content < min->content && last_min->content < stack->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
