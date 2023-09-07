/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:58:03 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/07 17:24:39 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour trier une pile de 4 éléments, il y a 23 options non-triées */

void	more_options4(t_list **li_src)
{
	t_list	*last;
	t_list	*third;
	t_list	*second;

	second = (*li_src)->next;
	third = second->next;
	last = third->next;
	if (second->value < (*li_src)->value
		&& second->value < third->value
		&& second->value < last->value)
		rotate_a(li_src);
	if (third->value < (*li_src)->value
		&& third->value < second->value
		&& third->value < last->value)
	{
		rotate_a(li_src);
		rotate_a(li_src);
	}
	if (last->value < second->value
		&& last->value < third->value
		&& last->value < (*li_src)->value)
		reverse_rotate_a(li_src);
}

void	sort_4(t_list **li_dest, t_list **li_src)
{
	more_options4(li_src);
	push_b(li_dest, li_src);
	sort_3(li_src);
	push_a(li_src, li_dest);
}
