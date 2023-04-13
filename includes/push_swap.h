/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:49:33 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/13 12:10:05 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Packages */

# include <stdio.h>
# include <unistd.h>
# include <limits.h> 
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/includes/libft.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Définition de la liste */

typedef struct ListElement
{
	int					value;
	int					index;
	struct ListElement	*next;
	struct ListElement	*prev;
}ListElement,	*t_list;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Prototypes des fonctions */

char	**arg_tab(int argc, char **argv);
int		tab_len(char **args);
void	free_tab(char **args);
long	*char_to_long(char **args);
int		err_msg(char **args, long *args_i);
void	push_a(ListElement **li_dest, ListElement **li_src);
void	push_b(ListElement **li_dest, ListElement **li_src);
void	rotate_a(ListElement **li);
void	rotate_b(ListElement **li);
void	reverse_rotate_a(ListElement **li);
void	reverse_rotate_b(ListElement **li);
void	swap_a(ListElement **li);
void	swap_b(ListElement **li);
void	swap_s(t_list *li_a, t_list *li_b);
t_list	new_list(char **args, long *args_i);
t_list	new_element(int value);
void	print_list(t_list li_A, t_list li_B);
int		list_length(t_list li);
void	clear_list(t_list *li);
void	insert_bottom_list(t_list *li, t_list new_element);
void	insert_top_list(t_list *li, t_list new_element);
t_list	remove_bottom_list(t_list *li);
t_list	remove_top_list(t_list *li);
void	sort_2(t_list *li);
void	sort_3(t_list *li);
void	sort_4(t_list *li_dest, t_list *li_src);
void	sort_5(t_list *li_dest, t_list *li_src);
long	min_chunk(int size, int act_chunk, int nbr_chunk);
int		max_chunk(int size, int act_chunk, int nbr_chunk);
int		scan_from_top(t_list li_a, long val_max_chunk);
int		scan_from_bottom(t_list li_a, long val_max_chunk);
int		get_index(t_list li_b, long value);
void	sort_big(t_list *li_a, t_list *li_b, char **args);
int		is_sorted(t_list li);
void	sort_launcher(t_list *li_a, t_list *li_b, char **args);
void	bubble_sort(char **args, long *args_i);

#endif