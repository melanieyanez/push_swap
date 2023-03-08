/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:29 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/08 16:56:37 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pour trier une pile de 3 éléments, il y a 5 options non-triées */

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
		reverse_rotate(li);
		swap(li);
	}	
	if ((*li)->value > mid->value
		&& mid->value < last->value
		&& last->value > (*li)->value)
	{
		swap(li);
	}
	if ((*li)->value < mid->value
		&& mid->value > last->value
		&& last->value < (*li)->value)
	{
		reverse_rotate(li);
	}
	if ((*li)->value > mid->value
		&& mid->value < last->value
		&& last->value < (*li)->value)
	{
		rotate(li);
	}
	if ((*li)->value > mid->value
		&& mid->value > last->value
		&& last->value < (*li)->value)
	{
		swap(li);
		reverse_rotate(li);
	}
}
