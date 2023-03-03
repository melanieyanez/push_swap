/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:49:33 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/01 13:05:36 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Packages */

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Définition de la liste */

typedef struct ListElement
{
	int					value;
	struct ListElement	*next;
}ListElement,	*t_list;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Prototypes des fonctions */

t_list	new_list(void);
int		is_empty_list(t_list li);
void	print_list(t_list li_A, t_list li_B);
void	insert_top_list(t_list *li, int x);
void	insert_bottom_list(t_list *li, int x);
void	remove_top_list(t_list *li);
void	remove_bottom_list(t_list *li);
void	clear_list2(t_list *li);
void	push(ListElement **li_dest, ListElement **li_src);
void	rotate(ListElement **li);
void	reverse_rotate(ListElement **li);
int		last_list_value(ListElement *li);
void	swap(ListElement **li);
int		list_length(t_list li);
void	sort_3(t_list *li);
t_list	remove_return_bottom_list(t_list *li);
void	insert_whole_top_list(t_list *li, t_list to_add);
void	clear_list(t_list *li);
t_list	remove_return_top_list(t_list li, t_list *li_ptr);

#endif