/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:29 by melanieyane       #+#    #+#             */
/*   Updated: 2023/02/06 13:34:25 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pour trier une liste de 3 éléments, j'utilise la méthode d'inversion qui est apparemment la plus efficace */

void	sort_3(t_list *li)
{
	t_list	*last;
	t_list	*mid;

	*mid = (**li)->next;
	*last = (**mid)->next;
	//printf("value top [%d] value mid [%d] value last [%d]", (**li).value, (**mid).value, (**last).value);
	//if (*li != NULL && *mid != NULL && *last != NULL)
	//{
	//	if ((**mid).value > (**li).value)
	//		swap(li);
	//}
}
