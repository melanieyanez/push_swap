/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:34:32 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/13 13:07:21 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* attention creer les fonctions avec list_b si besoin dans l'algo */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Prend le premier élément de la liste source */
/* pour le mettre au début de la liste de destination */

void	push_a(ListElement **li_dest, ListElement **li_src)
{
	if (is_empty_list(*li_src))
		return ;
	insert_top_list(li_dest, (**li_src).value);
	remove_top_list(li_src);
	printf("pa\n");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Prend le premier élément de la liste source */
/* pour le mettre au début de la liste de destination */

void	push_b(ListElement **li_dest, ListElement **li_src)
{
	if (is_empty_list(*li_src))
		return ;
	insert_top_list(li_dest, (**li_src).value);
	remove_top_list(li_src);
	printf("pb\n");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Décale tous les éléments vers le haut */
/* Le premier élément devient le dernier */

void	rotate(ListElement **li)
{
	insert_bottom_list(li, (**li).value);
	remove_top_list(li);
	printf("ra\n");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Décale tous les éléments vers le bas */
/* Le dernier élément devient le premier */

void	reverse_rotate(ListElement **li)
{
	insert_top_list(li, last_list_value(*li));
	remove_bottom_list(li);
	printf("rra\n");
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
	printf("sa\n");
}
