/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:57:08 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/13 17:59:26 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	long	*args_i;
	int		i;
	t_list	list_a;
	t_list	list_b;

	list_a = new_list();
	list_b = new_list();
	args = arg_tab(argc, argv);
	args_i = char_to_long(args);
	i = 0;
	if (argc <= 1 || err_msg(args, args_i) == 1)
	{
		free_tab(args);
		free(args_i);
		clear_list2(&list_a);
		clear_list2(&list_b);
		return (0);
	}
	while (i < tab_len(args))
	{
		insert_bottom_list(&list_a, args_i[i]);
		i ++;
	}
	//printf("Listes originales\n\n");
	//print_list(list_a, list_b);
	if (is_sorted(list_a) == 0)
		sort_launcher(&list_a, &list_b);
	//printf("Listes triées\n\n");
	//print_list(list_a, list_b);
	free_tab(args);
	free(args_i);
	clear_list2(&list_a);
	clear_list2(&list_b);
	//printf("Clear\n\n");
	//print_list(list_a, list_b);
	return (0);
}
