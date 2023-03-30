/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:37:50 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/30 12:52:11 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Trie mon tableau de int */

void	bubble_sort(char **args, long *args_i)
{
	int	i;
	int	temp;
	int	size;
	int	swap;

	size = tab_len(args);
	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (args_i[i] > args_i[i + 1])
			{
				temp = args_i[i];
				args_i[i] = args_i[i + 1];
				args_i[i + 1] = temp;
				swap = 1;
			}
			else
				i ++;
		}
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Calcule le nombre de chunk optimal en fonction de la longueur de la liste */

int	nbr_chunk(t_list *li)
{
	int	size;
	int	nbr_chunk;

	size = list_length(*li);
	if (size > 5 && size < 21)
		nbr_chunk = 2;
	if (size == 100)
		nbr_chunk = 5;
	if (size == 500)
		nbr_chunk = 12;
	else
		nbr_chunk = (((size * 7) / 400) + 3);
	return (nbr_chunk);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Scan ma liste depuis le haut pour trouver la valeur min */

int	scan_from_top(t_list li_a, long val_max_chunk)
{
	int	i;

	i = 0;
	while (li_a != NULL)
	{
		if (li_a->value <= val_max_chunk)
		{
			return (i);
		}
		li_a = li_a->next;
		i ++;
	}
	return (-1);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Scan ma liste depuis le bas pour trouver la valeur min */

int	scan_from_bottom(t_list li_a, long val_max_chunk)
{
	int	i;

	i = 1;
	while (li_a->next != NULL)
		li_a = li_a->next;
	while (li_a->prev != NULL)
	{
		if (li_a->value <= val_max_chunk)
		{
			return (i);
		}
		li_a = li_a->prev;
		i ++;
	}
	return (-1);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Renvoie l'index de la valeur recherchée */

int	get_index(t_list li_b, long value)
{
	int	i;

	i = 0;
	while (li_b != NULL)
	{
		if (li_b->value == value)
			return (i);
		li_b = li_b->next;
		i ++;
	}
	return (-1);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Renvoie le minimum d'un chunk donné */

long min_chunk(long *args_sorted, int size, int act_chunk, int nbr_chunk)
{
	if (act_chunk == 1)
		return (args_sorted[0]);
	return (args_sorted[(act_chunk - 1) * (size / nbr_chunk)]);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Renvoie le maximum d'un chunk donné */

long	max_chunk(long *args_sorted, int size, int act_chunk, int nbr_chunk)
{
	if (act_chunk == nbr_chunk)
		return (args_sorted[size - 1]);
	return (args_sorted[act_chunk * (size / nbr_chunk) - 1]);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pré-tri de la liste A en pushant vers B */

void	a_to_b(t_list *li_a, t_list *li_b, long val_max_chunk)
{
	int	nb_r;
	int	nb_rr;

	while (scan_from_top(*li_a, val_max_chunk) != -1
		&& scan_from_bottom(*li_a, val_max_chunk) != -1)
	{
		nb_r = scan_from_top(*li_a, val_max_chunk);
		nb_rr = scan_from_bottom(*li_a, val_max_chunk);
		if (nb_r <= nb_rr)
		{
			while (nb_r)
			{
				rotate_a(li_a);
				nb_r --;
			}
		}
		else
		{
			while (nb_rr)
			{
				reverse_rotate_a(li_a);
				nb_rr --;
			}
		}
		push_b(li_b, li_a);
	}
	push_b(li_b, li_a);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Tri de la liste B en pushant vers A */

void	b_to_a(t_list *li_a, t_list *li_b, long val_min_chunk, long val_max_chunk)
{
	long	value;
	int		nb_r;
	int		nb_rr;
	int		index;

	value = val_max_chunk;
	while (value >= val_min_chunk)
	{
		index = get_index(*li_b, value);
		if (index != -1)
		{
			nb_r = index;
			nb_rr = list_length(*li_b) - index;
			if (nb_r <= nb_rr)
			{
				while (nb_r)
				{
					rotate_b(li_b);
					nb_r --;
				}
			}
			else
			{
				while (nb_rr)
				{
					reverse_rotate_b(li_b);
					nb_rr --;
				}
			}
			push_a(li_a, li_b);
		}
		value --;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Process du tri d'une grande liste de nombres */

void	sort_big(t_list *li_a, t_list *li_b, char **args)
{
	long	*args_i_sorted;
	int		tablen;
	int		act_chunk;
	int		nb_chunk;

	act_chunk = 1;
	nb_chunk = nbr_chunk(li_a);
	args_i_sorted = char_to_long(args);
	tablen = tab_len(args);
	bubble_sort(args, args_i_sorted);
	while (act_chunk <= nb_chunk)
	{
		a_to_b(li_a, li_b, max_chunk(args_i_sorted, tablen, act_chunk, nb_chunk));
		act_chunk++;
	}
	act_chunk--;
	while (act_chunk >= 1)
	{
		b_to_a(li_a, li_b, min_chunk(args_i_sorted, tablen, act_chunk, nb_chunk), max_chunk(args_i_sorted, tablen, act_chunk, nb_chunk));
		act_chunk--;
	}
}

/*
int	main(int argc, char **argv)
{
	char	**args;
	long	*args_i;
	long	*args_i_sorted;
	int		act_chunk;
	int		nb_chunk;
	t_list	list_a;
	t_list	list_b;

	act_chunk = 1;
	args = arg_tab(argc, argv);
	args_i = char_to_long(args);
	args_i_sorted = char_to_long(args);
	bubble_sort(args, args_i_sorted);
	list_a = new_list(args, args_i);
	list_b = NULL;
	nb_chunk = nbr_chunk(&list_a);
	print_list(list_a, list_b);
	while (act_chunk <= nb_chunk)
	{
		while (scan_from_top(list_a, max_chunk(args_i_sorted, tab_len(args), act_chunk, nb_chunk)) != -1
			&& scan_from_bottom(list_a, max_chunk(args_i_sorted, tab_len(args), act_chunk, nb_chunk)) != -1)
		{
			a_to_b(&list_a, &list_b, max_chunk(args_i_sorted, tab_len(args), act_chunk, nb_chunk));
		}
		act_chunk++;
	}
	act_chunk--;
	while (act_chunk >= 1)
	{
		b_to_a(&list_a, &list_b, min_chunk(args_i_sorted, tab_len(args), act_chunk, nb_chunk),  max_chunk(args_i_sorted, tab_len(args), act_chunk, nb_chunk));
		act_chunk--;
	}
	return (0);
}
*/