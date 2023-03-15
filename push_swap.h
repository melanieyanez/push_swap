/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:49:33 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/15 17:50:36 by myanez-p         ###   ########.fr       */
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
void	push_a(ListElement **li_dest, ListElement **li_src);
void	push_b(ListElement **li_dest, ListElement **li_src);
void	rotate(ListElement **li);
void	reverse_rotate(ListElement **li);
int		last_list_value(ListElement *li);
void	swap(ListElement **li);
int		list_length(t_list li);
void	clear_list(t_list *li);
void	sort_2(t_list *li);
void	sort_3(t_list *li);
void	sort_4(t_list *li_dest, t_list *li_src);
void	sort_5(t_list *li_dest, t_list *li_src);
int		is_sorted(t_list li);
char	**arg_tab(int argc, char **argv);
void	free_tab(char **args);
long	ft_atol(const char *str);
long	*char_to_long(char **args);
int		check_number(char **args);
int		check_int(char **args, long *args_i);
int		check_double(char **args, long *args_i);
int		err_msg(char **args, long *args_i);
size_t	ft_strlen(char const *str);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		tab_len(char **args);
void	sort_launcher(t_list *li_a, t_list *li_b);

#endif