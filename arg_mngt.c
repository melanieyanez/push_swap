/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_mngt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:20:01 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/15 11:46:54 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction pour stocker la valeur de mes arguments dans un tableau de char */

char	**arg_tab(int argc, char **argv)
{
	char	*tmp;
	char	**args;
	int		i;

	if (argc == 2)
	{
		tmp = ft_strdup(argv[1]);
		args = ft_split(tmp, ' ');
		free(tmp);
	}
	else
	{
		i = 1;
		args = malloc(argc * sizeof(char *));
		if (args == NULL)
			return (NULL);
		while (i < argc)
		{
			args[i - 1] = ft_strdup(argv[i]);
			i ++;
		}
		args[i - 1] = NULL;
	}
	return (args);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction pour calculer le nombre d'éléments de mon tableau de char */

int	tab_len(char **args)
{
	int	size;

	size = 0;
	while (args[size])
		size ++;
	return (size);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction pour libérer mon tableau d'arguments en char */

void	free_tab(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i ++;
	}
	free(args);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour transformer une chaîne de char en long int */

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i ++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + str[i] - '0';
		else
			return (sign * result);
		i ++;
	}
	return (sign * result);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Pour transformer le tableau de char en tableau de long */
/* Pour pouvoir savoir si on est plus grand ou pas que le int min et max */
/* Long car avec un int on ne pourrait pas savoir */

long	*char_to_long(char **args)
{
	long	*result;
	int		i;

	result = malloc(tab_len(args) * sizeof(long));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (args[i])
	{
		result[i] = ft_atol(args[i]);
		i ++;
	}
	return (result);
}

/*
int	main(int argc, char **argv)
{
	char	**test;
	long	*testi;
	int		i;

	i = 0;
	test = arg_tab(argc, argv);
	while (test[i])
	{
		printf("arg_tab[%d] = \"%s\"\n", i, test[i]);
		i++;
	}
	testi = char_to_long(test);
	free_tab(test);
	i = 0;
	while (i < tab_len(test))
	{
		printf("arg %d: %ld\n", i, testi[i]);
		i ++;
	}
	free(testi);
	return (0);
}
*/
