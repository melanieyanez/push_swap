/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:57:08 by melanieyane       #+#    #+#             */
/*   Updated: 2023/02/03 17:03:54 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_list	list_a;
	t_list	list_b;

	list_a = new_list();
	list_b = new_list();
	printf("Création\n");
	print_list(list_a, list_b);
	list_a = insert_top_list(list_a, 12);
	list_a = insert_top_list(list_a, 45);
	list_a = insert_top_list(list_a, 4);
	list_b = insert_top_list(list_b, 28);
	list_b = insert_top_list(list_b, 76);
	list_b = insert_top_list(list_b, 43);
	printf("Top insertion\n");
	print_list(list_a, list_b);
	push(&list_a, &list_b);
	printf("Push\n");
	print_list(list_a, list_b);
	list_a = insert_bottom_list(list_a, -1);
	printf("Bottom insertion\n");
	print_list(list_a, list_b);
	swap(&list_a);
	printf("Swap\n");
	print_list(list_a, list_b);
	rotate(&list_a);
	printf("Rotate\n");
	print_list(list_a, list_b);
	reverse_rotate(&list_a);
	printf("Reverse rotate\n");
	print_list(list_a, list_b);
	remove_top_list(&list_a);
	printf("Remove top\n");
	print_list(list_a, list_b);
	list_a = remove_bottom_list(list_a);
	printf("Remove bottom\n");
	print_list(list_a, list_b);
	clear_list(&list_a);
	clear_list(&list_b);
	printf("Clear\n");
	print_list(list_a, list_b);
	return (0);
}
