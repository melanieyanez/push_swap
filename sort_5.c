/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:05:04 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/17 18:44:09 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour trier une pile de 5 éléments, il y a 119 options non-triées */

void	more_options5(t_list *li_src)
{
	t_list	last;
	t_list	fourth;
	t_list	third;
	t_list	second;

	second = (*li_src)->next;
	third = second->next;
	fourth = third->next;
	last = fourth->next;
	if (fourth->value < (*li_src)->value
		&& fourth->value < second->value
		&& fourth->value < third->value
		&& fourth->value < last->value)
	{
		reverse_rotate_a(li_src);
		reverse_rotate_a(li_src);
	}
	if (third->value < (*li_src)->value
		&& third->value < second->value
		&& third->value < fourth->value
		&& third->value < last->value)
	{
		rotate_a(li_src);
		rotate_a(li_src);
	}
}

void	sort_5(t_list *li_dest, t_list *li_src)
{
	t_list	last;
	t_list	fourth;
	t_list	third;
	t_list	second;

	second = (*li_src)->next;
	third = second->next;
	fourth = third->next;
	last = fourth->next;
	if (second->value < (*li_src)->value
		&& second->value < third->value
		&& second->value < fourth->value
		&& second->value < last->value)
		rotate_a(li_src);
	if (last->value < second->value
		&& last->value < third->value
		&& last->value < fourth->value
		&& last->value < (*li_src)->value)
		reverse_rotate_a(li_src);
	more_options5(li_src);
	push_b(li_dest, li_src);
	sort_4(li_dest, li_src);
	push_a(li_src, li_dest);
}
