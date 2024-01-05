/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:27:10 by ajurado-          #+#    #+#             */
/*   Updated: 2023/12/02 18:32:30 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_list **stack, char option)
{
	t_list *first;
	t_list *tmp;

	first = (*stack);
	tmp = (*stack)->next->next;
	(*stack) = (*stack)->next;
	(*stack)->next = first;
	first->next = tmp;
	if(option == 'a')
		ft_putendl_fd("sa", 1);
	else if (option == 'b')
		ft_putendl_fd("sb", 1);
}

void ft_swap_both(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a, 's');
	ft_swap(stack_b, 's');
	ft_putendl_fd("ss", 1);
}

void ft_push(t_list **org, t_list **dst, char dst_option)
{
	t_list *first;

	if (!ft_lstsize(*org))
		return ;
	first = *org;
	*org = (*org)->next;
	first->next = *dst;
	*dst = first;
	if(dst_option == 'a')
		ft_putendl_fd("pa", 1);
	else if (dst_option == 'b')
		ft_putendl_fd("pb", 1);
}
