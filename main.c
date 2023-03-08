/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:57:08 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/08 18:53:44 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	list_a;
	t_list	list_b;

	(void)argc;
	list_a = new_list();
	list_b = new_list();
	insert_top_list(&list_a, atoi(argv[5]));
	insert_top_list(&list_a, atoi(argv[4]));
	insert_top_list(&list_a, atoi(argv[3]));
	insert_top_list(&list_a, atoi(argv[2]));
	insert_top_list(&list_a, atoi(argv[1]));
	if (is_sorted(list_a))
		return (0);
	//printf("Listes originales\n\n");
	//print_list(list_a, list_b);
	//printf("Résultat sort 5\n\n");
	//sort_3(&list_a);
	sort_5(&list_b, &list_a);
	//print_list(list_a, list_b);
	clear_list2(&list_a);
	clear_list2(&list_b);
	//printf("Clear\n\n");
	//print_list(list_a, list_b);
	return (0);
}
