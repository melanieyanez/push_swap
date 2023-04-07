/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mvnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:26:52 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/07 16:53:03 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Retourne un pointeur sur le dernier élément de la liste */

t_list	last_list_element(t_list *li)
{
	t_list	element;

	if (li == NULL || *li == NULL)
		return (NULL);
	element = *li;
	while (element->next != NULL)
		element = element->next;
	return (element);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Ajoute un élément à la fin de la liste */

void	insert_bottom_list(t_list *li, t_list new_element)
{
	t_list	last_element;

	last_element = last_list_element(li);
	if (li != NULL)
	{
		if (*li == NULL)
			*li = new_element;
		if (last_element != NULL)
		{
			last_element->next = new_element;
			new_element->prev = last_element;
		}
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Supprime le dernier élément de la liste et renvoie un pointeur dessus */

t_list	remove_bottom_list(t_list *li)
{
	t_list	last_element;

	if (*li == NULL)
		return (NULL);
	last_element = last_list_element(li);
	if (last_element->prev == NULL && last_element->next == NULL)
	{
		*li = NULL;
		return (last_element);
	}
	else
	{
		(last_element->prev)->next = NULL;
		last_element->prev = NULL;
		last_element->next = NULL;
		return (last_element);
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Ajoute un élément au début de la liste */

void	insert_top_list(t_list *li, t_list new_element)
{
	if (li != NULL)
	{
		if (*li != NULL)
		{
			new_element->next = *li;
			(*li)->prev = new_element;
		}
		*li = new_element;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Supprime le dernier élément de la liste et renvoie un pointeur dessus */

t_list	remove_top_list(t_list *li)
{
	t_list	first_element;

	if (*li == NULL)
		return (NULL);
	first_element = *li;
	if (first_element->prev == NULL && first_element->next == NULL)
	{
		*li = NULL;
		return (first_element);
	}
	else
	{
		(first_element->next)->prev = NULL;
		*li = first_element->next;
		first_element->prev = NULL;
		first_element->next = NULL;
		return (first_element);
	}
}
