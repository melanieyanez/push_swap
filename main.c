/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:57:08 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/01 13:06:55 by melanieyane      ###   ########.fr       */
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
	insert_top_list(&list_a, 45);
	insert_top_list(&list_a, 12);
	insert_top_list(&list_a, 4);
	printf("Listes originales\n");
	print_list(list_a, list_b);
	insert_whole_top_list(&list_a, remove_return_bottom_list(&list_a));
	printf("Résultat remove bottom, add top\n");
	print_list(list_a, list_b);
	printf("Résultat remove return top\n");
	test = remove_return_top_list(list_a, &list_a);
	print_list(list_a, list_b);
	clear_list2(&list_a);
	clear_list2(&list_b);
	printf("Clear\n");
	print_list(list_a, list_b);
	return (0);
}
