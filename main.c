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

	printf("\x1b[33mlist a : \x1b[0m");
	while (current->start != 1 && current)
	{
		printf("%d ", current->number);
		current = current->next;
	}
	current = head;
	while (current->next)
		current = current->next;
	printf("\n\x1b[31mlist b : \x1b[0m");
	while (current->start != 1)
	{
		printf("%d ", current->number);
		current = current->prev;
	}
	printf("\n\n");
}

void push_swap(t_llist *head, t_llist *sorted, t_env *e)
{
	int chaos;	
	
	sorted = ft_sort(&sorted);
	//print_list(head);
	//ft_sa(head);
	//printf("sa.\n");
	//print_list(head);
	ft_pb(head);
	print_list(head);
	ft_pb(head);
	print_list(head);
	//ft_pb(head);
	//print_list(head);
	/*ft_pb(head);
	print_list(head);*/
	//print_list(head);
	//print_list(head);


	//if (e->i == 0)
	//	printf("plop\n");
	//print_list(sorted);
	chaos = ft_chaos(head, sorted, e);
	printf("chaos = %d\n", chaos);
}



void ft_init_e(t_env *e)
{
	e->i = 0;
}

int     main(int ac, char **av)
{
	t_env *e;
	t_llist *head;
	t_llist *sorted;
	
	if ((e = (t_env*)malloc(sizeof(t_env))) == NULL)
		return (0);
	if (ac != 1)
	{
		ft_init_e(e);
		head = ll_stock(av + 1);
		sorted = ll_stock(av + 1);
		printf("plop\n");
		push_swap(head,sorted, e);
	}
    return 0;
}

