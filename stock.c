/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:46:15 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/31 18:17:51 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*ll_stock(char **av)
{
	t_llist			*head;
	t_llist			*current;

	head = NULL;
	current = head;
	while (*av)
	{
		if (head == NULL)
		{
			head = ll_copy_new(head, *av);
			current = head;
		}
		else
		{
			while (current->next != NULL)
				current = current->next;
			current = ll_copy_cur(current, *av);
		}
		av++;
	}
	current->end = 1;
	return (head);
}

t_llist	*ll_copy_new(t_llist *head, char *av)
{
	t_llist *new;

	new = (t_llist*)malloc(sizeof(t_llist));
	new->next = head;
	head = new;
	new->number = ft_atoi(av);
	/*new->start = 0;
	new->end = 0;*/
	new->prev = NULL;
	return (new);
}

t_llist	*ll_copy_cur(t_llist *cur, char *av)
{
	t_llist *new;
	t_llist *temp;

	temp = cur;
	new = (t_llist*)malloc(sizeof(t_llist));
	cur->next = new;
	new->next = NULL;
	new->prev = temp;
	/*new->start = 0;
	new->end = 0;*/
	new->number = ft_atoi(av);
	return (new);
}
