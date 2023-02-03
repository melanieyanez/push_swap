/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:34:32 by melanieyane       #+#    #+#             */
/*   Updated: 2023/02/03 17:51:12 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Prend le premier élément de la liste source */
/* pour le mettre au début de la liste de destination */

void	push(ListElement **li_dest, ListElement **li_src)
{
	if (is_empty_list(*li_src))
		return ;
	insert_top_list(li_dest, (**li_src).value);
	remove_top_list(li_src);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Décale tous les éléments vers le haut */
/* Le premier élément devient le dernier */

void	rotate(ListElement **li)
{
	insert_bottom_list(li, (**li).value);
	remove_top_list(li);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Décale tous les éléments vers le bas */
/* Le dernier élément devient le premier */

void	reverse_rotate(ListElement **li)
{
	insert_top_list(li, last_list_value(*li));
	remove_bottom_list(li);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Intervertit les deux premiers éléments de la liste */

void	swap(ListElement **li)
{
	t_list	first;
	t_list	second;

	if (*li == NULL || (*li)->next == NULL)
		return ;
	first = *li;
	second = (*li)->next;
	first->next = second->next;
	second->next = first;
	*li = second;
}
