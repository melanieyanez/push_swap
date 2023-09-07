/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:49:33 by melanieyane       #+#    #+#             */
/*   Updated: 2023/09/07 17:29:34 by melanieyane      ###   ########.fr       */
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
}t_list;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Prototypes des fonctions */

//arg_mngt.c

char	**arg_tab(int argc, char **argv);
int		tab_len(char **args);
void	free_tab(char **args);
long	ft_atol(const char *str);
long	*char_to_long(char **args);

//err_mngt.c

int		check_number(char **args);
int		check_int(char **args, long *args_i);
int		check_double(char **args, long *args_i);
int		err_msg(char **args, long *args_i);

//list_mngt.c

t_list	*new_list(char **args, long *args_i);
t_list	*new_element(int value);
void	print_list(t_list *li_A, t_list *li_B);
int		list_length(t_list *li);
void	clear_list(t_list **li);

//list_mvnt.c

t_list	*last_list_element(t_list **li);
void	insert_bottom_list(t_list **li, t_list *new_element);
t_list	*remove_bottom_list(t_list **li);
void	insert_top_list(t_list **li, t_list *new_element);
t_list	*remove_top_list(t_list **li);

//instr_A.c

void	push_a(t_list **li_dest, t_list **li_src);
void	rotate_a(t_list **li);
void	reverse_rotate_a(t_list **li);
void	swap_a(t_list **li);

//instr_B.c

void	push_b(t_list **li_dest, t_list **li_src);
void	rotate_b(t_list **li);
void	reverse_rotate_b(t_list **li);
void	swap_b(t_list **li);
void	swap_s(t_list **li_a, t_list **li_b);

//sort_tools.c

int		is_sorted(t_list *li);
void	sort_launcher(t_list **li_a, t_list **li_b, char **args);
void	bubble_sort(char **args, long *args_i);

//sort_2.c, sort_3.c, sort_4.c, sort_5.c

void	sort_2(t_list **li);
void	more_options3(t_list **li);
void	sort_3(t_list **li);
void	more_options4(t_list **li_src);
void	sort_4(t_list **li_dest, t_list **li_src);
void	more_options5(t_list **li_src);
void	sort_5(t_list **li_dest, t_list **li_src);

//sort_big_tools.c

int		min_chunk(int size, int act_chunk, int nbr_chunk);
int		max_chunk(int size, int act_chunk, int nbr_chunk);
int		scan_from_top(t_list *li_a, long val_max_chunk);
int		scan_from_bottom(t_list *li_a, long val_max_chunk);
int		get_index(t_list *li_b, long value);

//sort_big.c

void	normalize(long *args_i_sorted, t_list **li_a);
int		nbr_chunk(t_list **li);
void	a_to_b(t_list **li_a, t_list **li_b, int val_max_chunk);
void	b_to_a(t_list **li_a, t_list **li_b, long val_min, long val_max);
void	sort_big(t_list **li_a, t_list **li_b, char **args);

#endif