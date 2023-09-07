/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_A.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:34:32 by melanieyane       #+#    #+#             */
/*   Updated: 2023/09/07 17:10:51 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Prend le premier élément de la liste source */
/* pour le mettre au début de la liste de destination */

void	push_a(t_list **li_dest, t_list **li_src)
{
	t_list	*temp;

	if (li_src != NULL && li_dest != NULL && list_length(*li_src) > 0)
	{
		temp = remove_top_list(li_src);
		insert_top_list(li_dest, temp);
		write(1, "pa\n", 3);
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Décale tous les éléments vers le haut */
/* Le premier élément devient le dernier */

void	rotate_a(t_list **li)
{
	t_list	*temp;

	temp = remove_top_list(li);
	insert_bottom_list(li, temp);
	write(1, "ra\n", 3);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Décale tous les éléments vers le bas */
/* Le dernier élément devient le premier */

void	reverse_rotate_a(t_list **li)
{
	t_list	*temp;

	temp = remove_bottom_list(li);
	insert_top_list(li, temp);
	write(1, "rra\n", 4);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Intervertit les deux premiers éléments de la liste */

void	swap_a(t_list **li)
{
	t_list	*first;
	t_list	*second;

	if (*li != NULL && list_length(*li) > 1)
	{
		first = remove_top_list(li);
		second = remove_top_list(li);
		insert_top_list(li, first);
		insert_top_list(li, second);
	}
	write(1, "sa\n", 3);
}
