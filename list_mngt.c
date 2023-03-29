/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mngt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:51:50 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/27 10:42:09 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Création d'une nouvelle structure */

t_list	new_list(char **args, long *args_i)
{
	t_list	current_element;
	t_list	first_element;
	int		size;

	first_element = NULL;
	size = 1;
	if (args_i != NULL)
	{
		first_element = new_element((int)args_i[0]);
		while (size < tab_len(args))
		{
			current_element = new_element((int)args_i[size]);
			insert_bottom_list(&first_element, current_element);
			size ++;
		}
	}
	return (first_element);
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Création d'un nouvel élément */

t_list	new_element(int value)
{
	t_list	element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->value = value;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour afficher la liste */
/* Attention remplacer par mon printf */
/* Enlever les deux dernières lignes pour le rendu */

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
			printf("		[%d]\n", li_B->value);
			li_B = li_B->next;
		}
	}
	printf(" A		 B\n");
	printf("\n");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour connaître le nombre d'éléments de la liste */

int	list_length(t_list li)
{
	int	size;

	size = 0;
	if (li != NULL)
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

/* Pour libérer la liste */

void	clear_list(t_list *li)
{
	t_list	element;

	if (*li == NULL)
		return ;
	while (*li != NULL)
	{
		element = *li;
		*li = (*li)->next;
		free (element);
		element = NULL;
	}
}
