/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:05 by ajurado-          #+#    #+#             */
/*   Updated: 2023/12/10 19:44:29 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (a)
	{
		ft_putnbr_fd(((t_stack *) a->content)->index, 1);
		ft_putendl_fd("", 1);
		a = a->next;
	}
	return (0);
}