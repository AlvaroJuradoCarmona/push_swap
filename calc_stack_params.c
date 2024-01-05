#include "push_swap.h"

void	ft_get_pos(t_list **stack)
{
	t_list	*aux;
	int	i;

	aux = *stack;
	i = 0;
	while (aux)
	{
		((t_stack *)aux->content)->pos = i;
		i++;
		aux = aux->next;
	}
}

static int	get_target(t_list **a, int b_idx, int target_idx, int target_pos)
{
	t_list	*aux_a;

	aux_a = *a;
	while (aux_a)
	{
		if (((t_stack *)aux_a->content)->index > b_idx && ((t_stack *)aux_a->content)->index < target_idx)
		{
			target_idx = ((t_stack *)aux_a->content)->index;
			target_pos = ((t_stack *)aux_a->content)->pos;
		}
		aux_a = aux_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
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

void	ft_get_target_pos(t_list **a, t_list **b)
{
	t_list	*aux_b;
	int	target_pos;
	
	aux_b = *b;
	target_pos = 0;
	while(aux_b)
	{
		target_pos = get_target(a, ((t_stack *)aux_b->content)->index, INT_MAX, target_pos);
		((t_stack *)aux_b->content)->target_pos = target_pos;
		aux_b = aux_b->next;
	}
}

void	ft_cost_b(t_list **b)
{
	t_list	*aux_b;
	int	size_b;
	
	aux_b = *b;
	size_b = ft_lstsize(*b);
	while (aux_b)
	{
		if ((((t_stack *)aux_b->content)->pos + 1) <= size_b / 2 + 1)
			((t_stack *)aux_b->content)->cost_b = ((t_stack *)aux_b->content)->pos;
		else
			((t_stack *)aux_b->content)->cost_b = ((t_stack *)aux_b->content)->pos - size_b;
		aux_b = aux_b->next;
	}
}

void	ft_cost_a(t_list **a, t_list **b)
{
	t_list	*aux_b;
	int	size_a;
	t_stack *s;
	
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
