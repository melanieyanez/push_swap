/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_mngt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:07:02 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/15 11:46:19 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Remplacer les conditions par la fct is_digit */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction pour checker si tous mes arguments sont des nombres */

int	check_number(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][0] == '+' || args[i][0] == '-')
		{
			if (args[i][1] >= 48 && args[i][1] <= 57)
				j ++;
			else
				return (1);
		}
		while (args[i][j])
		{
			if (args[i][j] < 48 || args[i][j] > 57)
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour checker que tous mes nombres rentrent dans un int */

int	check_int(char **args, long *args_i)
{
	int	i;

	i = 0;
	while (i < tab_len(args))
	{
		if (args_i[i] > INT_MAX || args_i[i] < INT_MIN)
			return (1);
		i ++;
	}
	return (0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour checker qu'on n'a pas deux fois le même nombre */

int	check_double(char **args, long *args_i)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab_len(args))
	{
		j = i + 1;
		while (args_i[j])
		{
			if (args_i[i] == args_i[j])
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Check toutes les erreurs potentielles et sort un message d'erreur si oui */

int	err_msg(char **args, long *args_i)
{
	if (check_number(args) == 1
		|| check_int(args, args_i) == 1
		|| check_double(args, args_i) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

/*
int	main(int argc, char **argv)
{
	char	**test;
	long	*testi;
	int		i;

	i = 0;
	test = arg_tab(argc, argv);
	testi = char_to_long(test);
	while (i < tab_len(test))
	{
		printf("arg %d: %ld\n", i, testi[i]);
		i ++;
	}
	printf("%d\n", err_msg(test, testi));
	free_tab(test);
	free(testi);
	return (0);
}
*/
