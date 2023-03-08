/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:05:04 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/08 18:57:46 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		rotate(li_src);
	}
	if (third->value < (*li_src)->value
		&& third->value < second->value
		&& third->value < fourth->value
		&& third->value < last->value)
	{
		rotate(li_src);
		rotate(li_src);
	}
	if (fourth->value < (*li_src)->value
		&& fourth->value < second->value
		&& fourth->value < third->value
		&& fourth->value < last->value)
	{
		reverse_rotate(li_src);
		reverse_rotate(li_src);
	}
	if (last->value < second->value
		&& last->value < third->value
		&& last->value < fourth->value
		&& last->value < (*li_src)->value)
	{
		reverse_rotate(li_src);
	}
	push_b(li_dest, li_src);
	sort_4(li_dest, li_src);
	push_a(li_src, li_dest);
}
