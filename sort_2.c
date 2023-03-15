/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:30:45 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/15 11:50:48 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pour trier une pile de 2 éléments, il y a 1 option non-triée */

void	sort_2(t_list *li)
{
	t_list	second;

	second = (*li)->next;
	if ((*li)->value > second->value)
		swap(li);
}
