#include "push_swap.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static void	ft_reverse_loop(t_list **a, t_list **b)
{
	t_list	*aux_b;
	t_stack *s;
	
	aux_b = *b;
	s = ((t_stack *)aux_b->content);
	while(s->cost_a < 0 && s->cost_b < 0)
	{
		s->cost_a++;
		s->cost_b++;
		ft_reverse_both(a, b);
	} 
}

static void	ft_rotate_loop(t_list **a, t_list **b)
{
	t_list	*aux_b;
	t_stack *s;
	
	aux_b = *b;
	s = ((t_stack *)aux_b->content);
	while(s->cost_a > 0 && s->cost_b > 0)
	{
		s->cost_a--;
		s->cost_b--;
		ft_rotate_both(a, b);
	} 
}

void	ft_select_moves(t_list **a, t_list **b, t_stack *lowest)
{
	t_stack *s;
	
	s = lowest;
	if (s->cost_a < 0 && s->cost_b < 0)
		ft_reverse_loop(a, b);
	else if (s->cost_a > 0 && s->cost_b > 0)
		ft_rotate_loop(a, b);	
	while (s->cost_a > 0)
	{
		ft_rotate(a, 'a');
		s->cost_a--;
	}
	while (s->cost_a < 0)
	{
		ft_reverse(a, 'a');
		s->cost_a++;
	}
	while (s->cost_b > 0)
	{
		ft_rotate(b, 'b');
		s->cost_b--;
	}
	while (s->cost_b < 0)
	{
		ft_reverse(b, 'b');
		s->cost_b++;
	}
	ft_push(b, a, 'a');
}

void	ft_do_move(t_list **a, t_list **b)
{
	t_list	*aux_b;
	t_stack *lowest;
	int	lowest_cost;
	
	aux_b = *b;
	lowest_cost = INT_MAX;
	while(aux_b)
	{
		if((ft_abs(((t_stack *)aux_b->content)->cost_a) + ft_abs(((t_stack *)aux_b->content)->cost_b)) < lowest_cost)
		{
			lowest = ((t_stack *)aux_b->content);
			lowest_cost = (ft_abs(((t_stack *)aux_b->content)->cost_a) + ft_abs(((t_stack *)aux_b->content)->cost_b));
		}
		aux_b = aux_b->next;
	}	
	ft_select_moves(a, b, lowest);
}
