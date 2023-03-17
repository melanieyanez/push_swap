/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:50:33 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/17 19:15:52 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour vérifier si la liste est déjà triée */

int	is_sorted(t_list li)
{
	t_list	temp;

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

void	sort_launcher(t_list *li_a, t_list *li_b)
{
	if (list_length(*li_a) == 2)
		sort_2(li_a);
	else if (list_length(*li_a) == 3)
		sort_3(li_a);
	else if (list_length(*li_a) == 4)
		sort_4(li_b, li_a);
	else if (list_length(*li_a) == 5)
		sort_5(li_b, li_a);
	//else if (list_length(*li_a) > 5)
	//	sort_big(li_b, li_a);
}
