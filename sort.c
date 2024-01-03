#include "push_swap.h"

static void	ft_push_all_except_three(t_list *a, t_list *b)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_lstsize(a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if (a->content->index <= size / 2)
		{
            ft_push(a, b, 'b');
			pushed++;
		}
		else
            ft_rotate(a, 'a');
			do_ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		ft_push(a, b, 'b');
		pushed++;
	}
}

void    ft_sort_large(t_list *a, t_list *b)
{
    ft_push_all_except_three(a, b);
    ft_sort_three_nodes(a);
}