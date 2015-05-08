/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 15:08:50 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/08 15:09:09 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/includes/libft.h"

typedef struct	s_env
{
	int			i;
}				t_env;

typedef struct		s_llist
{
	int				number;
	struct s_llist	*next;
}					t_llist;



t_llist	*ll_copy_new(t_llist *head, char *av);
t_llist	*ll_copy_cur(t_llist *cur, char *av);
t_llist	*ll_stock(char **av);
void	merge_sort(t_llist **ref);
t_llist	*merge(t_llist *a, t_llist *b);
void	split(t_llist *source, t_llist **front, t_llist **back);
void	push_swap(t_llist *head, t_llist *sorted, t_env *e);
t_llist *ft_sort(t_llist **head);
int		ft_chaos(t_llist *head, t_llist *sorted, t_env *e);
void	ft_s(t_llist *current);
void	ft_ss(t_llist *a, t_llist *b);

#endif