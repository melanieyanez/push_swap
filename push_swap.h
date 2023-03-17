/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:49:33 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/17 18:23:42 by melanieyane      ###   ########.fr       */
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

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Définition de la liste */

typedef struct ListElement
{
	int					value;
	struct ListElement	*next;
	struct ListElement	*prev;
}ListElement,	*t_list;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Prototypes des fonctions */

size_t	ft_strlen(char const *str);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
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
int		is_sorted(t_list li);
void	sort_launcher(t_list *li_a, t_list *li_b);

#endif