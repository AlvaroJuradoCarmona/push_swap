/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:05 by ajurado-          #+#    #+#             */
/*   Updated: 2023/12/02 17:24:31 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	if(argc < 2 || !ft_check_args(argv))
		ft_putstr_fd("Error\n", 2);
	a = ft_calloc(argc - 1, sizeof(t_list));
	if (!a)
		ft_putstr_fd("Error\n", 2);
	b = ft_calloc(argc - 1, sizeof(t_list));
	if (!b)
		ft_putstr_fd("Error\n", 2);
	return (0);
}