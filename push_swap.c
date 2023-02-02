/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:11:00 by myanez-p          #+#    #+#             */
/*   Updated: 2023/02/02 20:36:40 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* affiche la liste */
/*ajoute un element*/
/* enleve un element*/

typedef struct element
{
	int				value;
	struct element	*next;
	struct element	*prev;
}	t_element;

void	swap(t_element **top_el)
{
	int	tmp;

	if (*top_el == NULL || (*top_el) ->next == NULL)
		return ;
	tmp = (**top_el).value;
	(**top_el).value = (**top_a);
}

void	sa(t_element **top_a)
{
	int	tmp;

	if (*top_a == NULL || (*top_a)->next == NULL)
		return ;
	tmp = (**top_a).value;
	(**top_a).value = (**top_a).next->value;
	(**top_a).next->value = tmp;
}

void	sb(t_element **top_b)
{
	int	tmp;

	if (*top_b == NULL || (*top_b)->next == NULL)
		return ;
	tmp = (**top_b).value;
	(**top_b).value = (**top_b).next->value;
	(**top_b).next->value = tmp;
}

void	ss(t_element **top_a, t_element **top_b)
{
	sa(*top_a);
	sb(*top_b);
}

void	ra(t_element **top)
{
	t_element	*last;
	t_element	*new_last;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	last = *top;
	while (last->next != NULL)
		last = last->next;
	last->next = *top;
	/* le dernier devient le premier */
	new_last = *top;
	/* le premier element devient le dernier*/
	*top = (*top)->next;
	/* comme je monte tout dun cran, mon premier element devient le deuxieme qui est contenu dans next*/
	new_last->next = NULL;
	/* il sagit du dernier element de ma liste donc next ne pointe sur rien*/
}
