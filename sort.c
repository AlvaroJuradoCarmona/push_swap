/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:36 by ajurado-          #+#    #+#             */
/*   Updated: 2024/01/08 18:06:26 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_all_except_three(t_list **a, t_list **b)
{
	int	size;
	int	pushed;

	size = ft_lstsize(*a);
	pushed = 0;
	while (pushed < size / 2)
	{
		if (((t_stack *)(*a)->content)->index <= size / 2)
		{
			ft_push(a, b, 'b');
			pushed++;
		}
		else
			ft_rotate(a, 'a');
	}
	while (size - pushed > 3)
	{
		ft_push(a, b, 'b');
		pushed++;
	}
	ft_sort_three_nodes(a);
}

void	ft_get_pos(t_list **stack)
{
	t_list	*aux;
	int		i;

	aux = *stack;
	i = 0;
	while (aux)
	{
		((t_stack *)aux->content)->pos = i;
		i++;
		aux = aux->next;
	}
}

static int	ft_get_lowest_index(t_list **stack)
{
	t_list	*aux;
	int		lowest_index;
	int		lowest_pos;

	aux = *stack;
	lowest_index = INT_MAX;
	ft_get_pos(stack);
	lowest_pos = ((t_stack *)aux->content)->pos;
	while (aux)
	{
		if (((t_stack *)aux->content)->index < lowest_index)
		{
			lowest_index = ((t_stack *)aux->content)->index;
			lowest_pos = ((t_stack *)aux->content)->pos;
		}
		aux = aux->next;
	}
	return (lowest_pos);
}

static void	ft_adjust(t_list **a)
{
	int	lowest_pos;
	int	size_a;

	size_a = ft_lstsize(*a);
	lowest_pos = ft_get_lowest_index(a);
	if (lowest_pos > size_a / 2)
	{
		while (lowest_pos < size_a)
		{
			ft_reverse(a, 'a');
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_rotate(a, 'a');
			lowest_pos--;
		}
	}
}

void	ft_sort_large(t_list **a, t_list **b)
{
	ft_push_all_except_three(a, b);
	while (*b)
	{
		ft_get_pos(a);
		ft_get_pos(b);
		ft_get_target_pos(a, b);
		ft_cost_b(b);
		ft_cost_a(a, b);
		ft_do_move(a, b);
	}
	if (!ft_is_sorted(*a))
		ft_adjust(a);
}
