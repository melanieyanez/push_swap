/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:57:08 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/06 17:20:08 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_list	list_a;
	t_list	list_b;
	t_list	test;

	list_a = new_list();
	list_b = new_list();
	insert_top_list(&list_a, 2);
	insert_top_list(&list_a, 1);
	insert_top_list(&list_a, 3);
	printf("Listes originales\n");
	print_list(list_a, list_b);
	printf("Résultat sort 3\n");
	sort_3(&list_a);
	print_list(list_a, list_b);
	clear_list2(&list_a);
	clear_list2(&list_b);
	printf("Clear\n");
	print_list(list_a, list_b);
	return (0);
}
