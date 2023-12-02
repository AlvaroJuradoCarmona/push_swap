/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:27:10 by ajurado-          #+#    #+#             */
/*   Updated: 2023/12/02 18:29:52 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_two_nodes(t_list *stack)
{
	if (stack->content->value > stack->next->content->value)
		ft_swap(stack, 'a');
}

void ft_sort_three_nodes(t_list *stack)
{
	
	if (stack->content->value < stack->next->content->value &&
	stack->next->next->content->value < stack->next->content->value)
		ft_reverse(stack, 'a');
	else if (stack->content->value > stack->next->content->value &&
	stack->content->value > stack->next->next->content->value)
		ft_rotate(stack, 'a');
	ft_sort_two_nodes(stack);
}

