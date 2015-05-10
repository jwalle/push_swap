
#include "push_swap.h"

int 	ft_a_empty(t_llist *head)
{
	t_llist *current;
	int i;

	i = 0;
	current = head;
	while (current)
	{
		i += current->end;
		current = current->next;
	}
	if (!i)
		return (1);
	return (0);
}

int		ft_b_empty(t_llist *head)
{
	t_llist *current;

	current = head;
	while (current)
	{
		if (current->start && current->end)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_ll_swap(t_llist *one, t_llist *two)
{
	int temp;

	temp = one->number;
	one->number = two->number; 
	two->number = temp;
}

void	ft_ra(t_llist *head)
{
	t_llist *current;
	int temp_end;
	//int temp;

	current = head;
	if (ft_a_empty(current))
		return ;
	while (current)
	{
		if (current->next->end)
			break;
		current = current->next;
	}
	temp_end = current->next->number;
	current = current->next;
	while (current->prev)
	{
		/*temp = current->number;
		current->number = current->prev->number;
		current->prev->number = temp;*/
		ft_ll_swap(current, current->prev);
		if (!current->prev->prev)
		{
			current->prev->number = temp_end;
			break;
		}
		current = current->prev;
	}
}

void 	ft_rb(t_llist *head)
{
	t_llist *current;
	int		temp;

	current = head;
	if (ft_b_empty(current))
		return ;
	while (current->next)
		current = current->next;
	temp = current->next->number;
	current = current->next;
	while (current->prev)
	{
		ft_ll_swap(current, current->prev);
		if (current->prev->start)
		{
			current->prev->number = temp;
			break;
		}
		current = current->prev;
	}

}