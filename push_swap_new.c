/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:44:26 by melanieyane       #+#    #+#             */
/*   Updated: 2023/02/02 20:12:46 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Création d'une nouvelle structure */

t_list	new_list(void)
{
	return (NULL);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour vérifier si la liste est vide */

int	is_empty_list(t_list li)
{
	if (li == NULL)
		return (1);
	return (0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour afficher la liste */
/* Attention remplacer par mon printf */

void	print_list(t_list li_A, t_list li_B)
{	
	printf("A: ");
	if (is_empty_list(li_A))
		printf("EMPTY");
	while (li_A != NULL)
	{
		printf("[%d] ", li_A->value);
		li_A = li_A->next;
	}
	printf("\n");
	printf("B: ");
	if (is_empty_list(li_B))
		printf("EMPTY");
	while (li_B != NULL)
	{
		printf("[%d] ", li_B->value);
		li_B = li_B->next;
	}
	printf("\n");
	printf("\n");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour ajouter un élément en début de liste */

t_list	insert_top_list(t_list li, int x)
{
	t_list	element;

	element = malloc(sizeof(element));
	if (element == NULL)
		return (NULL);
	element->value = x;
	if (is_empty_list(li))
		element->next = NULL;
	else
		element->next = li;
	return (element);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour ajouter un élément en fin de liste */

t_list	insert_bottom_list(t_list li, int x)
{
	t_list	element;
	t_list	temp;

	element = malloc(sizeof(element));
	if (element == NULL)
		return (NULL);
	element->value = x;
	element->next = NULL;
	if (is_empty_list(li))
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (li);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour enlever un élément en début de liste */

t_list	remove_top_list(t_list li)
{
	t_list	element;

	element = malloc (sizeof(element));
	if (element == NULL)
		return (NULL);
	if (is_empty_list(li))
		return (li);
	element = li->next;
	free (li);
	li = NULL;
	return (element);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour enlever un élément en fin de liste */

t_list	remove_bottom_list(t_list li)
{
	t_list	temp;
	t_list	before;

	temp = li;
	before = li;
	if (is_empty_list(li))
		return (li);
	if (li->next == NULL)
	{
		free(li);
		li = NULL;
		return (new_list());
	}
	while (temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
	return (li);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour libérer la liste */

t_list	clear_list(t_list li)
{
	if (is_empty_list(li))
		return (li);
	while (li != NULL)
		li = remove_top_list(li);
	return (li);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour récupérer la valeur du dernier élément */

int	last_list_value(ListElement *li)
{
	int	last_value;

	while ((li)->next != NULL)
		li = li->next;
	last_value = (*li).value;
	return (last_value);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour connaître le nombre d'éléments de la liste */

int	list_length(t_list li)
{
	int	size;

	size = 0;
	if (!is_empty_list(li))
	{
		while (li != NULL)
		{
			++size;
			li = li->next;
		}
	}
	return (size);
}
