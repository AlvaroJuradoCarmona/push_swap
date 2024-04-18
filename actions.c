/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:13:43 by ajurado-          #+#    #+#             */
/*   Updated: 2024/01/08 17:23:10 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static void	ft_reverse_loop(t_list **a, t_list **b)
{
	t_list	*aux_b;
	t_stack	*s;

	aux_b = *b;
	s = ((t_stack *)aux_b->content);
	while (s->cost_a < 0 && s->cost_b < 0)
	{
		s->cost_a++;
		s->cost_b++;
		ft_reverse_both(a, b);
	}
}

static void	ft_rotate_loop(t_list **a, t_list **b)
{
	t_list	*aux_b;
	t_stack	*s;

	aux_b = *b;
	s = ((t_stack *)aux_b->content);
	while (s->cost_a > 0 && s->cost_b > 0)
	{
		s->cost_a--;
		s->cost_b--;
		ft_rotate_both(a, b);
	}
}

void	ft_select_moves(t_list **a, t_list **b, t_stack *lowest)
{
	if (lowest->cost_a < 0 && lowest->cost_b < 0)
		ft_reverse_loop(a, b);
	else if (lowest->cost_a > 0 && lowest->cost_b > 0)
		ft_rotate_loop(a, b);
	while (lowest->cost_a > 0)
	{
		ft_rotate(a, 'a');
		lowest->cost_a--;
	}
	while (lowest->cost_a < 0)
	{
		ft_reverse(a, 'a');
		lowest->cost_a++;
	}
	while (lowest->cost_b > 0)
	{
		ft_rotate(b, 'b');
		lowest->cost_b--;
	}
	while (lowest->cost_b < 0)
	{
		ft_reverse(b, 'b');
		lowest->cost_b++;
	}
	ft_push(b, a, 'a');
}

void	ft_do_move(t_list **a, t_list **b)
{
	t_list	*aux_b;
	t_stack	*lowest;
	t_stack	*s;
	int		lowest_cost;

	aux_b = *b;
	lowest_cost = INT_MAX;
	while (aux_b)
	{
		s = ((t_stack *)aux_b->content);
		if ((ft_abs(s->cost_a) + ft_abs(s->cost_b)) < lowest_cost)
		{
			lowest = ((t_stack *)aux_b->content);
			lowest_cost = (ft_abs(s->cost_a) + ft_abs(s->cost_b));
		}
		aux_b = aux_b->next;
	}
	ft_select_moves(a, b, lowest);
}
