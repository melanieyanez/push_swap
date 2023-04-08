/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_mngt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:07:02 by myanez-p          #+#    #+#             */
/*   Updated: 2023/04/08 12:09:15 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (ft_isdigit(args[i][1]) == 1)
				j ++;
			else
				return (1);
		}
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0)
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
