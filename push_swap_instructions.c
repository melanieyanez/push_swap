/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:34:32 by melanieyane       #+#    #+#             */
/*   Updated: 2023/02/02 20:17:28 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(ListElement **li_dest, ListElement **li_src)
{
	if (is_empty_list(*li_src))
		return ;
	*li_dest = insert_top_list(*li_dest, (**li_src).value);
	*li_src = remove_top_list(*li_src);
}

void	rotate(ListElement **li)
{
	*li = insert_bottom_list(*li, (**li).value);
	*li = remove_top_list(*li);
}

void	reverse_rotate(ListElement **li)
{
	*li = insert_top_list(*li, last_list_value(*li));
	*li = remove_bottom_list(*li);
}

void	swap(ListElement **li)
{
	t_list	first;
	t_list	second;

	if (*li == NULL || (*li)->next == NULL)
		return ;
	first = *li;
	second = (*li)->next;
	first->next = second->next;
	second->next = first;
	*li = second;
}
