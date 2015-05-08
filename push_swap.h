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

typedef struct	s_llist
{
	int			number;
	void		*next;
}				t_llist;

t_llist	*ll_copy_new(t_llist *head, char *av);
t_llist	*ll_copy_cur(t_llist *cur, char *av);
t_llist	*ll_stock(char **av);

#endif