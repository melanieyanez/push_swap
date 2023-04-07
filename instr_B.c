/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_B.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:34:32 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/07 12:22:03 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Prend le premier élément de la liste source */
/* pour le mettre au début de la liste de destination */

void	push_b(ListElement **li_dest, ListElement **li_src)
{
	t_list	temp;

	if (li_src != NULL && li_dest != NULL && list_length(*li_src) > 0)
	{
		temp = remove_top_list(li_src);
		insert_top_list(li_dest, temp);
		write(1, "pb\n", 3);
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Décale tous les éléments vers le haut */
/* Le premier élément devient le dernier */

void	rotate_b(ListElement **li)
{
	t_list	temp;

	temp = remove_top_list(li);
	insert_bottom_list(li, temp);
	write(1, "rb\n", 3);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Décale tous les éléments vers le bas */
/* Le dernier élément devient le premier */

void	reverse_rotate_b(ListElement **li)
{
	t_list	temp;

	temp = remove_bottom_list(li);
	insert_top_list(li, temp);
	write(1, "rrb\n", 4);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Intervertit les deux premiers éléments de la liste */

void	swap_b(ListElement **li)
{
	t_list	first;
	t_list	second;

	if (*li != NULL && list_length(*li) > 1)
	{
		first = remove_top_list(li);
		second = remove_top_list(li);
		insert_top_list(li, first);
		insert_top_list(li, second);
	}
	write(1, "sb\n", 3);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Intervertit les deux premiers éléments des deux listes */

void	swap_s(t_list *li_a, t_list *li_b)
{
	t_list	first;
	t_list	second;

	if (*li_a != NULL && list_length(*li_a) > 1)
	{
		first = remove_top_list(li_a);
		second = remove_top_list(li_a);
		insert_top_list(li_a, first);
		insert_top_list(li_a, second);
	}
	if (*li_b != NULL && list_length(*li_b) > 1)
	{
		first = remove_top_list(li_b);
		second = remove_top_list(li_b);
		insert_top_list(li_b, first);
		insert_top_list(li_b, second);
	}
	write(1, "ss\n", 3);
}
