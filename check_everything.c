/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_everything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:24:40 by pvillena          #+#    #+#             */
/*   Updated: 2022/02/11 12:56:45 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_digit(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			if (ft_strlen(numbers[i]) > 11 || ft_isnumber(numbers[i]) == 0)
			{
				ft_free(numbers);
				ft_printf("Error");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_repeat_nbr(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_strncmp(numbers[i], numbers[j], 10) == 0)
			{
				ft_free(numbers);
				ft_printf("Error");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

t_list	*check_numbers(char **numbers)
{
	t_list	*first_number;

	check_digit(numbers);
	check_repeat_nbr(numbers);
	first_number = nbrs_2_lst(numbers);
	return (first_number);
}
