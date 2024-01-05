/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:35 by ajurado-          #+#    #+#             */
/*   Updated: 2023/12/10 19:10:02 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int	value;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
}	t_stack;

int		ft_check_args(char **argv);
void	ft_fill_values (t_list **a, int argc, char **argv);
void	ft_sort_two_nodes(t_list **stack);
void	ft_sort_three_nodes(t_list **stack);
void	ft_rotate(t_list **stack, char option);
void	ft_rotate_both(t_list **stack_a, t_list **stack_b);
void	ft_reverse(t_list **stack, char option);
void	ft_reverse_both(t_list **stack_a, t_list **stack_b);
void	ft_swap(t_list **stack, char option);
void	ft_swap_both(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **org, t_list **dst, char dst_option);
void	ft_assign_indexes(t_list **a, int argc);
int		ft_is_sorted(t_list *a);
void    ft_sort_large(t_list **a, t_list **b);
void	ft_get_pos(t_list **stack);
void	ft_get_target_pos(t_list **a, t_list **b);
void	ft_cost_b(t_list **b);
void	ft_cost_a(t_list **a, t_list **b);
void	ft_do_move(t_list **a, t_list **b);
void	ft_select_moves(t_list **a, t_list **b, t_stack *lowest);

#endif
