/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:57:08 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/17 12:08:24 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

void	check_digit(char **numbers);
void	check_repeat_nbr(char **numbers);
t_list	*check_numbers(char **numbers);
void	ft_free(char **numbers);
void	ft_swap(t_list **stack, char stackc);
void	ft_swap_both(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **from, t_list **to, char toc);
void	ft_rotate(t_list **stack, char stackc);
void	ft_reverse_rotate(t_list **stack, char stackc);
void	ft_sort_3(t_list **stack);
t_list	*ft_sort(t_list *stack, t_list *stack_b);
t_list	*nbrs_2_lst(char **numbers);
t_list	*get_list(int argc, char **argv);
int		ft_atoi_check(const char *str, char **numbers);
int		ft_isnumber(char *s);
int		ft_position_lst(t_list *stack, t_list *element);
int		check_list(t_list *stack);
t_list	*ft_copy_list(t_list *stack);
void	ft_sort_4(t_list **stack, t_list **stack_b);
void	ft_sort_5(t_list **stack, t_list **stack_b);
t_list	*ft_lstmin(t_list *stack);
t_list	*ft_lstmax(t_list *stack);
t_list	*next_min(t_list *stack, t_list *last_min);
void	ft_sort_big_stack(t_list **stack, t_list **stack_b, size_t n);
void	ft_sort_biggest(t_list **stack, t_list **stack_b);
char	ft_shortest_way(t_list *stack, int midpoint);
char	ft_shortest_way_max(t_list *stack, int midpoint);
void	ft_sort100(t_list **stack, t_list **stack_b);
char	find_less_than(t_list *stack, int n);
void	ft_find_push(t_list **stack, t_list **stack_b);
void	ft_radix(t_list **stack_a, t_list **stack_b);
void	ft_free_temp(t_list **temp, t_list **temp2);
#endif