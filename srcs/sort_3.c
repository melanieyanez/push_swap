/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:29 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/17 18:43:32 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour trier une pile de 3 éléments, il y a 5 options non-triées */

void	more_options3(t_list *li)
{
	t_list	last;
	t_list	mid;

	mid = (*li)->next;
	last = mid->next;
	if ((*li)->value < mid->value
		&& mid->value > last->value
		&& last->value < (*li)->value)
		reverse_rotate_a(li);
	if ((*li)->value > mid->value
		&& mid->value < last->value
		&& last->value < (*li)->value)
		rotate_a(li);
	if ((*li)->value > mid->value
		&& mid->value > last->value
		&& last->value < (*li)->value)
	{
		swap_a(li);
		reverse_rotate_a(li);
	}
}

void	sort_3(t_list *li)
{
	t_list	last;
	t_list	mid;

	mid = (*li)->next;
	last = mid->next;
	if (li == NULL || mid == NULL || last == NULL)
		return ;
	if ((*li)->value < mid->value
		&& mid->value > last->value
		&& last->value > (*li)->value)
	{
		reverse_rotate_a(li);
		swap_a(li);
	}	
	if ((*li)->value > mid->value
		&& mid->value < last->value
		&& last->value > (*li)->value)
		swap_a(li);
	more_options3(li);
}
