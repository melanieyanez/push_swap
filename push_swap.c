/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:44:26 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/13 17:52:29 by myanez-p         ###   ########.fr       */
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
	if (li_A != NULL && li_B != NULL)
	{
		while (li_A != NULL && li_B != NULL)
		{
			printf("[%d]		[%d]\n", li_A->value, li_B->value);
			li_A = li_A->next;
			li_B = li_B->next;
		}
	}
	if (li_A != NULL && li_B == NULL)
	{
		while (li_A != NULL)
		{
			printf("[%d]		\n", li_A->value);
			li_A = li_A->next;
		}
	}
	if (li_A == NULL && li_B != NULL)
	{
		while (li_B != NULL)
		{
			printf("		[%d]\n", li_A->value);
			li_B = li_B->next;
		}
	}
	printf(" A		 B\n");
	printf("\n");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour ajouter un élément en début de liste en donnant la valeur de l'int */

void	insert_top_list(t_list *li, int x)
{
	t_list	element;

	element = malloc(sizeof(element));
	if (element == NULL)
		return ;
	element->value = x;
	if (is_empty_list(*li))
		element->next = NULL;
	else
		element->next = *li;
	*li = element;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour ajouter un élément en fin de liste */

void	insert_bottom_list(t_list *li, int x)
{
	t_list	element;
	t_list	temp;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return ;
	element->value = x;
	element->next = NULL;
	if (is_empty_list(*li))
	{
		*li = element;
		return ;
	}
	temp = *li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour enlever un élément en début de liste */

void	remove_top_list(t_list *li)
{
	t_list	element;

	if (is_empty_list(*li))
		return ;
	element = *li;
	*li = (*li)->next;
	free (element);
	element = NULL;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour enlever un élément en début de liste et le retourner */

t_list	remove_return_top_list(t_list li, t_list *li_ptr)
{
	t_list	element;

	if (is_empty_list(*li_ptr))
		return (NULL);
	element = li;
	element->next = NULL;
	//*li_ptr = (*li_ptr)->next;
	print_list(element, *li_ptr);
	return (element);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour enlever un élément en fin de liste */

void	remove_bottom_list(t_list *li)
{
	t_list	temp;
	t_list	before;

	temp = *li;
	before = *li;
	if (is_empty_list(*li))
		return ;
	if ((*li)->next == NULL)
	{
		free(*li);
		*li = NULL;
		return ;
	}
	while (temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour libérer la liste, no leaks à 42 */

void	clear_list(t_list *li)
{
	if (is_empty_list(*li))
		return ;
	while ((*li)->next != NULL)
	{
		free(*li);
		*li = (*li)->next;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour libérer la liste, no leaks à la maison */

void	clear_list2(t_list *li)
{
	if (is_empty_list(*li))
		return ;
	while (*li != NULL)
		remove_top_list(li);
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

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour supprimer le dernier élément de la liste */
/* mais retourner un pointeur sur celui-ci sans le free */

t_list	remove_return_bottom_list(t_list *li)
{
	t_list	temp;
	t_list	before;

	temp = *li;
	before = *li;
	if (is_empty_list(*li))
		return (NULL);
	if ((*li)->next == NULL)
	{
		free(*li);
		*li = NULL;
		return (NULL);
	}
	while (temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	return (temp);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour ajouter un élément déjà existant au sommet de la liste */

void	insert_whole_top_list(t_list *li, t_list to_add)
{
	if (is_empty_list(*li))
		to_add->next = NULL;
	else
		to_add->next = *li;
	*li = to_add;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour vérifier si la liste est déjà triée */

int	is_sorted(t_list li)
{
	t_list	temp;

	temp = li->next;
	while (temp != NULL)
	{
		if (li->value > temp->value)
			return (0);
		li = li->next;
		temp = temp->next;
	}
	free (temp);
	return (1);
}

/* Pour lancer le tri */

void	sort_launcher(t_list *li_a, t_list *li_b)
{
	if (list_length(*li_a) == 2)
		sort_2(li_a);
	else if (list_length(*li_a) == 3)
		sort_3(li_a);
	else if (list_length(*li_a) == 4)
		sort_4(li_b, li_a);
	else if (list_length(*li_a) == 5)
		sort_5(li_b, li_a);
}
