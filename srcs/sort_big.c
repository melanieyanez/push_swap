/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:37:50 by myanez-p          #+#    #+#             */
/*   Updated: 2023/04/07 17:30:37 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Normalise les différentes valeurs de la liste originale */

void	normalize(long *args_i_sorted, t_list *li_a)
{
	int		i;
	int		j;
	int		list_len;
	t_list	current_element;

	i = 0;
	list_len = list_length(*li_a);
	current_element = *li_a;
	while (i < list_len)
	{
		j = 0;
		while (j < list_len)
		{
			if (args_i_sorted[j] == current_element->value)
			{
				current_element->index = j;
			}
			j++;
		}
		current_element = current_element->next;
		i++;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Calcule le nombre de chunk optimal en fonction de la longueur de la liste */

int	nbr_chunk(t_list *li)
{
	int	size;

	size = list_length(*li);
	if (size > 5 && size < 21)
		return (2);
	if (size == 100)
		return (5);
	if (size == 500)
		return (12);
	else
		return (((size * 7) / 400) + 3);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pré-tri de la liste A en pushant vers B */

void	a_to_b(t_list *li_a, t_list *li_b, int val_max_chunk)
{
	int	nb_r;
	int	nb_rr;

	while (scan_from_top(*li_a, val_max_chunk) != -1)
	{
		nb_r = scan_from_top(*li_a, val_max_chunk);
		nb_rr = scan_from_bottom(*li_a, val_max_chunk);
		if (nb_r <= nb_rr)
		{
			while (nb_r --)
				rotate_a(li_a);
		}
		else
		{
			while (nb_rr --)
				reverse_rotate_a(li_a);
		}
		push_b(li_b, li_a);
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Tri de la liste B en pushant vers A */

void	b_to_a(t_list *li_a, t_list *li_b, long val_min, long val_max)
{
	long	value;
	int		nb_r;
	int		nb_rr;

	value = val_max;
	while (value >= val_min)
	{
		if (get_index(*li_b, value) != -1)
		{
			nb_r = get_index(*li_b, value);
			nb_rr = list_length(*li_b) - get_index(*li_b, value);
			if (nb_r <= nb_rr)
			{
				while (nb_r --)
					rotate_b(li_b);
			}
			else
			{
				while (nb_rr --)
					reverse_rotate_b(li_b);
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
	int		len;
	int		act_chunk;
	int		nb_chunk;

	act_chunk = 1;
	nb_chunk = nbr_chunk(li_a);
	args_i_sorted = char_to_long(args);
	len = tab_len(args);
	bubble_sort(args, args_i_sorted);
	normalize(args_i_sorted, li_a);
	while (act_chunk <= nb_chunk)
	{
		a_to_b(li_a, li_b, max_chunk(len, act_chunk, nb_chunk));
		act_chunk++;
	}
	act_chunk--;
	while (act_chunk >= 1)
	{
		b_to_a(li_a, li_b, min_chunk(len, act_chunk, nb_chunk),
			max_chunk(len, act_chunk, nb_chunk));
		act_chunk--;
	}
	free (args_i_sorted);
}
