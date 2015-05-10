# include "push_swap.h"



void	ft_sa(t_llist *current)
{
	t_llist *swap;
	int temp;

	if (!current)
		return ;
	swap = current;
	if (!swap || !swap->next)
		return ;
	while (swap->next->end == 0)
		swap = swap->next;
	
	temp = swap->number;
	swap->number = swap->next->number;
	swap->next->number = temp;
}


void	ft_sb(t_llist *current)
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
	ft_sa(a);
	ft_sb(b);
}

void	ft_pb(t_llist *current)
{
	t_llist *swap;
	int		i;

	i = 0;
	swap = current;
	while (swap)
	{
		i += swap->end;
		swap = swap->next;
	}
	swap = current;
	if (!i)
		return;
	swap = current;
	while (swap && !swap->end)
		swap = swap->next;
	if (swap->prev)
		swap->prev->end = 1;
	swap->end = 0;


}

void	ft_pa(t_llist *current)
{
	t_llist *swap;
	int		i;

	i = 0;
	swap = current;
	while (swap)
	{
		i += swap->end;
		swap = swap->next;
	}
	swap = current;
	if (!i)
	{
		swap->end = 1;
		return;
	}
	while (swap->end != 1)
		swap = swap->next;
	if (swap->next == NULL)
		return ;
	swap->end = 0;
	swap->next->end = 1;
}

/*
void	ft_pb(t_llist *a, t_llist *b)
*/