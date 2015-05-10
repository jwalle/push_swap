
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

int		ft_a_only_one(t_llist *head)
{
	t_llist *current;
	int i;

	i = 0;
	current = head;
	while (current)
	{
		i++;
		if (current->end)
			break ;
		current = current->next;
	}
	if (i == 1)
		return (1);
	return (0);

}

int 	ft_b_only_one(t_llist *head)
{
	t_llist *current;
	int i;

	i = 0;
	current = head;
	while (current)
	{
		if (current->start && current->end)
			return (i);
		i++;
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

	current = head;
	//printf("one a = %d, one b = %d\n", ft_a_only_one(current), ft_b_only_one(current));
	if (ft_a_empty(current) || ft_a_only_one(current))
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
	if (ft_b_empty(current) || ft_b_only_one(current) == 1)
		return ;
	while (current->next && !current->next->start)
		current = current->next;
	if (ft_b_len(head) == 2)
	{
		//printf("current = %d, next = %d\n", current->number, current->next->number);
		ft_ll_swap(current, current->next);
		return ;
	}
	temp = current->next->number;
	current = current->next;
	while (current->next)
	{
		ft_ll_swap(current, current->next);
		if (current->next->start)
		{
			current->next->number = temp;
			break;
		}
		current = current->next;
	}	

}

void ft_rr(t_llist *head)
{
	t_llist *current;

	current = head;

	ft_ra(current);
	ft_rb(current);
}



