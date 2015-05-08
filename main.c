/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 15:06:46 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/08 15:08:40 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_list(t_llist *head)
{
	t_llist *current;

	current = head;
	while (current)
	{
		printf("%d\n", current->number);
		current = current->next;
	}
}


void push_swap(t_llist *head, t_env *e)
{
	if (e->i == 0)
		printf("plop\n");
	print_list(head);
}


void ft_init_e(t_env *e)
{
	e->i = 0;
}

int     main(int ac, char **av)
{
	t_env *e;
	t_llist *head;
	
	if ((e = (t_env*)malloc(sizeof(t_env))) == NULL)
		return (0);
	if (ac != 1)
	{
		ft_init_e(e);
		head = ll_stock(av + 1);
		push_swap(head, e);
	}
    return 0;
}

