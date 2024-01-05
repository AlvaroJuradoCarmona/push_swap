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

void	ft_get_target_pos(t_list **a, t_list **b)
{
	t_list	*aux_a;
	t_list	*aux_b;
	int	target;
	
	aux_b = *b;
	while(aux_b)
	{
		target = 0;
		aux_a = *a;
		while(aux_a)
		{
			if(((t_stack *)aux_b->content)->value > ((t_stack *)aux_a->content)->value)
			{
				aux_a = aux_a->next;
				target++;
			}
			else
			{
				((t_stack *)aux_b->content)->target_pos = target;
				break ;
			}
		}
		aux_b = aux_b->next;
	}
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
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
		if ((s->target_pos + 1) <= size_a / 2 + 1)
			s->cost_a = s->target_pos;
		else
			s->cost_a = s->target_pos - size_a;
		s->total_cost = ft_abs(s->cost_a) + ft_abs(s->cost_b);
		aux_b = aux_b->next;
	}
}
