/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:05 by ajurado-          #+#    #+#             */
/*   Updated: 2024/01/08 17:50:13 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *a)
{
	t_stack	*s;

	while (a->next != NULL)
	{
		s = ((t_stack *)a->content);
		if (s->value > ((t_stack *)a->next->content)->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	ft_sorted_assign(t_list **a, t_list **b, int size)
{
	if (ft_is_sorted(*a))
		return ;
	if (size == 2)
		ft_sort_two_nodes(&(*a));
	else if (size == 3)
		ft_sort_three_nodes(&(*a));
	else
		ft_sort_large(&(*a), &(*b));
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2 || !ft_check_args(argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = NULL;
	b = NULL;
	ft_fill_values(&a, argc, argv);
	ft_assign_indexes(&a, argc);
	ft_sorted_assign(&a, &b, ft_lstsize(a));
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
