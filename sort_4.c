/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:58:03 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/08 17:02:31 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_list *li_dest, t_list *li_src)
{
	t_list	last;
	t_list	third;
	t_list	second;

	second = (*li_src)->next;
	third = second->next;
	last = third->next;
	if (second->value < (*li_src)->value && second->value < third->value && second->value < last->value)
	{
		rotate(li_src);
	}
	if (third->value < (*li_src)->value && third->value < second->value && third->value < last->value)
	{
		rotate(li_src);
		rotate(li_src);
	}
	if(last->value < second->value && last->value < third->value && last->value < (*li_src)->value)
	{
		reverse_rotate(li_src);
	}
	push_b(li_dest, li_src);
	sort_3(li_src);
	push_a(li_src, li_dest);
}