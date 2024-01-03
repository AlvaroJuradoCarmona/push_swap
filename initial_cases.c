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
    if (((t_stack *)(stack->content))->value > ((t_stack *)(stack->next->content))->value)
        ft_swap(stack, 'a');
}

void ft_sort_three_nodes(t_list *stack)
{
    t_stack *s1 = (t_stack *)(stack->content);
    t_stack *s2 = (t_stack *)(stack->next->content);
    t_stack *s3 = (t_stack *)(stack->next->next->content);
    if (s1->value < s2->value && s3->value < s2->value){
        ft_reverse(stack, 'a');
    }else if (s1->value > s2->value && s1->value > s3->value){
        ft_rotate(stack, 'a');
        
    	if (s1->value > s2->value)
    		ft_swap(stack, 'a');
    }
}

