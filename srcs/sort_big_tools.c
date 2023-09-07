/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:39:54 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/07 19:20:53 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Renvoie le minimum d'un chunk donné */

int	min_chunk(int size, int act_chunk, int nbr_chunk)
{
	if (act_chunk == 1)
		return (0);
	return ((act_chunk - 1) * (size / nbr_chunk));
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Renvoie le maximum d'un chunk donné */

int	max_chunk(int size, int act_chunk, int nbr_chunk)
{
	if (act_chunk == nbr_chunk)
		return (size - 1);
	return (act_chunk * (size / nbr_chunk) - 1);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Scan ma liste depuis le haut pour trouver une valeur du chunk */

int	scan_from_top(t_list *li_a, long val_max_chunk)
{
	int	i;

	i = 0;
	while (li_a != NULL)
	{
		if (li_a->index <= val_max_chunk)
		{
			return (i);
		}
		li_a = li_a->next;
		i ++;
	}
	return (-1);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Scan ma liste depuis le bas pour trouver une valeur contenue dans le chunk */

int	scan_from_bottom(t_list *li_a, long val_max_chunk)
{
	int		i;
	int		list_len;
	t_list	*current_element;

	i = 1;
	list_len = list_length(li_a);
	current_element = li_a;
	while (i < list_len)
	{
		current_element = current_element->next;
		i++;
	}
	while (i)
	{
		if (current_element->index <= val_max_chunk)
			return (list_len - i + 1);
		current_element = current_element->prev;
		i --;
	}
	return (-1);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Renvoie l'index de la valeur recherchée */

int	get_index(t_list *li_b, long value)
{
	int	i;

	i = 0;
	while (li_b != NULL)
	{
		if (li_b->index == value)
			return (i);
		li_b = li_b->next;
		i ++;
	}
	return (-1);
}
