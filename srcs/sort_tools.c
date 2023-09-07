/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:50:33 by melanieyane       #+#    #+#             */
/*   Updated: 2023/09/07 17:20:37 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour vérifier si la liste est déjà triée */

int	is_sorted(t_list *li)
{
	t_list	*temp;

	temp = li->next;
	while (temp != NULL)
	{
		if (li->value > temp->value)
			return (0);
		li = li->next;
		temp = temp->next;
	}
	free (temp);
	return (1);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour lancer le tri */

void	sort_launcher(t_list **li_a, t_list **li_b, char **args)
{
	int	size;

	size = list_length(*li_a);
	if (size == 2)
		sort_2(li_a);
	else if (size == 3)
		sort_3(li_a);
	else if (size == 4)
		sort_4(li_b, li_a);
	else if (size == 5)
		sort_5(li_b, li_a);
	else if (size > 5)
		sort_big(li_a, li_b, args);
}

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
