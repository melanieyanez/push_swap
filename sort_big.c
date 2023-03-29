/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:37:50 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/27 18:26:23 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

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

int	nbr_chunk(t_list *li)
{
	int	size;
	int	nbr_chunk;

	size = list_length(*li);
	if (size < 21)
		nbr_chunk = 2;
	if (size >= 21 && size <= 100)
		nbr_chunk = 5;
	return (nbr_chunk);
}

/* scan depuis le haut pour trouver ma valeur min */
/* pas t_list *li_a car je ne veux pas la modifier */

int	scan_from_top(t_list li_a, long val_max_chunk)
{
	int	value;
	int	i;

	i = 0;
	value = 0;
	while (li_a != NULL)
	{
		if (li_a->value <= val_max_chunk)
		{
			value = li_a->value ;
			return (i);
		}
		li_a = li_a->next;
		i ++;
	}
	return (-1);
}

/* scan depuis le bas pour trouver ma valeur la plus petite */

int	scan_from_bottom(t_list li_a, long val_max_chunk)
{
	int	value;
	int	i;

	i = list_length(li_a);
	value = 0;
	while (li_a->next != NULL)
		li_a = li_a->next;
	while (li_a->prev != NULL)
	{
		if (li_a->value <= val_max_chunk)
		{
			value = li_a->value ;
			return (i);
		}
		li_a = li_a->prev;
		i --;
	}
	return (-1);
}

long	max_chunk(long *args_sorted, int size, int act_chunk, int nbr_chunk)
{
	if (act_chunk == nbr_chunk)
		return (args_sorted[size - 1]);
	return (args_sorted[act_chunk * (size / nbr_chunk) - 1]);
}

void	a_to_b(t_list *li_a, t_list *li_b, long val_max_chunk)
{
	int	nb_r;
	int	nb_rr;

	nb_r = scan_from_top(*li_a, val_max_chunk);
	nb_rr = list_length(*li_a) - scan_from_bottom(*li_a, val_max_chunk) + 1;
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
	if (list_length(*li_a) == 1)
		push_b(li_b, li_a);
	print_list(*li_a, *li_b);
}

void	b_to_a(t_list *li_a, t_list *li_b, long val_max_chunk)
{
	int	nb_r;
	int	nb_rr;

	nb_r = scan_from_top_a(*li_a, val_max_chunk);
	nb_rr = list_length(*li_a) - scan_from_bottom(*li_a, val_max_chunk) + 1;
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
	if (list_length(*li_a) == 1)
		push_b(li_b, li_a);
	print_list(*li_a, *li_b);
}

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
	print_list(list_a, list_b);
	//while (list_b != NULL)
	//{
	//	b_to_a();
	//}
	return (0);
}
