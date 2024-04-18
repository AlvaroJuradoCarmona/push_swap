/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:26 by ajurado-          #+#    #+#             */
/*   Updated: 2024/01/08 17:47:20 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

static int	ft_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
		}
	}
	return (0);
}

int	ft_check_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_is_number(argv[i]))
			return (0);
	}
	if (ft_duplicates(argv))
		return (0);
	return (1);
}
