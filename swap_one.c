# include "push_swap.h"

void	ft_s(t_llist *current)
{
	t_llist *swap;
	int temp;

	if (!current)
		return ;
	swap = current;
	if (!swap || !swap->next)
		return ;
	while (swap->next->next != NULL)
		swap = swap->next;
	temp = swap->number;

	swap->number = swap->next->number;
	swap->next->number = temp;
}

void	ft_ss(t_llist *a, t_llist *b)
{
	if (!a || !b)
		return ;
	if (!a->next || !b->next)
		return ;
	ft_s(a);
	ft_s(b);
}

/*
void	ft_pa(t_llist *a, t_llist *b)
{

}

void	ft_pb(t_llist *a, t_llist *b)
*/