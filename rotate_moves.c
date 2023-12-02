/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:27:10 by ajurado-          #+#    #+#             */
/*   Updated: 2023/12/02 17:51:21 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate(t_list *stack, char option)
{
	t_list *aux;
	t_list *last;

	aux = stack;
	stack = stack->next;
	last = ft_lstlast(stack);
	aux->next = NULL;
	last->next = aux;
	if(option == 'a')
		ft_putendl_fd("ra", 1);
	else if (option == 'b')
		ft_putendl_fd("rb", 1);
}

void ft_rotate_both(t_list *stack_a, t_list *stack_b)
{
	ft_rotate(stack_a, 'r');
	ft_rotate(stack_b, 'r');
	ft_putendl_fd("rr", 1);
}

void ft_reverse(t_list *stack, char option)
{
	t_list *aux;
	t_list *last;

	aux = stack;
	last = ft_lstlast(stack);
	while(aux->next->next != NULL)
		aux = aux->next;
	aux->next = NULL;
	last->next = stack;
	stack = last;
	if(option == 'a')
		ft_putendl_fd("rra", 1);
	else if (option == 'b')
		ft_putendl_fd("rrb", 1);
}

void ft_reverse_both(t_list *stack_a, t_list *stack_b)
{
	ft_reverse(stack_a, 'r');
	ft_reverse(stack_b, 'r');
	ft_putendl_fd("rrr", 1);
}
