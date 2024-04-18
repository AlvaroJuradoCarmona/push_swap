/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_stack_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:24:23 by ajurado-          #+#    #+#             */
/*   Updated: 2024/01/08 18:07:18 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_targt_bns(t_list **a, int target_idx, int target_pos)
{
	t_list	*aux_a;

	aux_a = *a;
	while (aux_a)
	{
		if (((t_stack *)aux_a->content)->index < target_idx)
		{
			target_idx = ((t_stack *)aux_a->content)->index;
			target_pos = ((t_stack *)aux_a->content)->pos;
		}
		aux_a = aux_a->next;
	}
	return (target_pos);
}

static int	get_target(t_list **a, int b_idx, int target_idx, int target_pos)
{
	t_list	*aux_a;
	t_stack	*s;

	aux_a = *a;
	while (aux_a)
	{
		s = ((t_stack *)aux_a->content);
		if (s->index > b_idx && s->index < target_idx)
		{
			target_idx = s->index;
			target_pos = s->pos;
		}
		aux_a = aux_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	target_pos = get_targt_bns(a, target_idx, target_pos);
	return (target_pos);
}

void	ft_get_target_pos(t_list **a, t_list **b)
{
	t_list	*aux_b;
	t_stack	*s;
	int		target_pos;

	aux_b = *b;
	target_pos = 0;
	while (aux_b)
	{
		s = ((t_stack *)aux_b->content);
		target_pos = get_target(a, s->index, INT_MAX, target_pos);
		((t_stack *)aux_b->content)->target_pos = target_pos;
		aux_b = aux_b->next;
	}
}

void	ft_cost_b(t_list **b)
{
	t_list	*aux_b;
	t_stack	*s;
	int		size_b;

	aux_b = *b;
	size_b = ft_lstsize(*b);
	while (aux_b)
	{
		s = ((t_stack *)aux_b->content);
		if ((s->pos + 1) <= size_b / 2 + 1)
			s->cost_b = s->pos;
		else
			s->cost_b = s->pos - size_b;
		aux_b = aux_b->next;
	}
}

void	ft_cost_a(t_list **a, t_list **b)
{
	t_list	*aux_b;
	int		size_a;
	t_stack	*s;

	aux_b = *b;
	size_a = ft_lstsize(*a);
	while (aux_b)
	{
		s = ((t_stack *)aux_b->content);
		s->cost_a = s->target_pos;
		if (s->target_pos > size_a / 2)
			s->cost_a = (size_a - s->target_pos) * -1;
		aux_b = aux_b->next;
	}
}
