/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:46:15 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/05 14:46:17 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist *ft_sort(t_llist **head)
{
	t_llist **ref;

	ref = head;
	merge_sort(ref);
	return(*ref);
}

void	merge_sort(t_llist **ref)
{
	t_llist *head;
	t_llist *a;
	t_llist *b;

	head = *ref;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*ref = merge(a, b);
}

t_llist	*merge(t_llist *a, t_llist *b)
{
	t_llist *result;

	if (!a)
		return (b);
	if (!b)
		return (a);
	if (a->number > b->number)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next);
	}
	return (result);
}

void	split(t_llist *source, t_llist **front, t_llist **back)
{
	t_llist	*fast;
	t_llist *slow;

	if (!source || !source->next)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = source;
		*back = slow->next;
		slow->next = NULL;
	}
}
