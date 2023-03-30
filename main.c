/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:57:08 by melanieyane       #+#    #+#             */
/*   Updated: 2023/03/30 16:36:58 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	long	*args_i;
	t_list	list_a;
	t_list	list_b;

	if (argc == 1)
		return (0);
	args = arg_tab(argc, argv);
	args_i = char_to_long(args);
	if (tab_len(args) == 0 || err_msg(args, args_i) == 1)
	{
		free_tab(args);
		free(args_i);
		return (0);
	}
	list_a = new_list(args, args_i);
	list_b = NULL;
	//printf("Listes originales\n\n");
	//print_list(list_a, list_b);
	if (is_sorted(list_a) == 0)
		sort_launcher(&list_a, &list_b, args);
	//printf("Listes triées\n\n");
	//print_list(list_a, list_b);
	free_tab(args);
	free(args_i);
	clear_list(&list_a);
	clear_list(&list_b);
	//printf("Clear\n\n");
	//print_list(list_a, list_b);
	return (0);
}
