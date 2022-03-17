/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:03:02 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/15 12:13:43 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*first_a;
	t_list	*first_b;

	first_b = NULL;
	if (argc <= 1)
		return (0);
	first_a = get_list(argc, argv);
	if (check_list(first_a) == 0)
	{
		ft_lstclear(&first_a);
		return (0);
	}
	first_a = ft_sort(first_a, first_b);
	ft_lstclear(&first_a);
	return (0);
}
