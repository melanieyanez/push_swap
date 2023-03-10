/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:49:33 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/10 17:45:28 by myanez-p         ###   ########.fr       */
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
void	push_a(ListElement **li_dest, ListElement **li_src);
void	push_b(ListElement **li_dest, ListElement **li_src);
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
void	sort_2(t_list *li);
void	sort_3(t_list *li);
void	sort_4(t_list *li_dest, t_list *li_src);
void	sort_5(t_list *li_dest, t_list *li_src);
int		is_sorted(t_list li);
char	**arg_tab(int argc, char **argv);
void	free_tab(char **args);
int		check_number(char **args);

#endif