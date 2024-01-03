/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:41:48 by ajurado-          #+#    #+#             */
/*   Updated: 2023/12/10 19:51:40 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_stack_new(int value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}

void	ft_fill_values(t_list **a, int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*stack;

	i = 0;
	while (++i < argc)
	{
		num = ft_atoi(argv[i]);
		stack = ft_stack_new(num);
		if (!stack)
		{
			if (*a)
				ft_lstclear(a, free);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(a, ft_lstnew(stack));
	}
}

void	ft_assign_indexes(t_list **a, int argc)
{
	t_list	*aux;
	t_stack	*lowest;
	int		i;
	int		num;
	t_stack	*content;

	i = 0;
	while (++i < argc)
	{
		num = INT_MAX;
		lowest = NULL;
		aux = *a;
		while (aux)
		{
			content = ((t_stack *) aux->content);
			if (content->index == 0 && content->value < num)
			{
				num = content->value;
				lowest = content;
			}
			aux = aux->next;
		}
		lowest->index = i;
	}
}
