
#include "push_swap.h"


static int ft_cmp(t_llist *a, t_llist *b)
{
	//printf("a = %d, b = %d\n", a->number, b->number);
	if (a->number == b->number)
		return (1);
	return (0);
}

int	ft_b_len(t_llist *head)
{
	t_llist *current;
	int		i;


	i = 0;
	current = head;
	if (ft_b_empty(current))
		return (0);
	if (ft_b_only_one(current))
		return (1);
	while (current)
	{
		if (current->start)
			break;
		current = current->next;
	}
	while (current->prev)
	{
		i++;
		if (current->prev->end)
			break;
		current = current->prev;
	}
	return (i);
}



int	ft_chaos(t_llist *head, t_llist *sorted, t_env *e)
{
	t_llist *current_head;
	t_llist *current_sort;
	t_llist *current_sort_r;
	t_llist *current_sort_l;
	int ret;
	int l;
	int r;

	(void)e;
	ret = 0;
	current_head = head;
	current_sort = sorted;
	while(current_head)
	{
		l = 0;
		r = 0;
		current_sort_r = current_sort;
		current_sort_l = current_sort;
		while ((!ft_cmp(current_sort_l, current_head)) &&
				(!ft_cmp(current_sort_r, current_head)) && 
				(current_sort_r || current_sort_l))
		{
			if (current_sort_r->next)
				current_sort_r = current_sort_r->next;
			if (current_sort_l->prev)
				current_sort_l = current_sort_l->prev;
			r += 1;
			l += 1;
			if (current_sort_r->number == current_head->number)
				ret += r;
			if (current_sort_l->number == current_head->number)
				ret += l;
		}
		current_head = current_head->next;
		current_sort = current_sort->next;
	}
	ret += ft_b_len(head);
	return (ret);
}

		//printf("i = %d number_head = %d\n", i, current_head->number);
