
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

void	ft_ra(t_llist *head)
{
	t_llist *current;
	int temp_end;
	int temp;

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
		temp = current->number;
		current->number = current->prev->number;
		current->prev->number = temp;
		if (!current->prev->prev)
		{
			current->prev->number = temp_end;
			break;
		}
		current = current->prev;
	}
}