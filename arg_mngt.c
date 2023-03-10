/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_mngt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:20:01 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/10 18:00:06 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* attention remplacer strdup par mon ft_strdup */

#include "push_swap.h"

/* Fonction pour stocker la valeur de mes arguments dans un tableau de char */

char	**arg_tab(int argc, char **argv)
{
	char	**args;
	int		i;

	i = 1;
	if (argc <= 1)
		return (NULL);
	args = malloc(argc * sizeof(char *));
	while (i < argc)
	{
		args[i - 1] = strdup(argv[i]);
		i ++;
	}
	args[i - 1] = NULL;
	return (args);
}

/* Fonction pour libérer mon tableau d'arguments */

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

/* Créer un tableau de int */
/* Faire un atol (copier atoi mais avec long) pr changer mon tab de char en int */

/*
int	main(int argc, char **argv)
{
	char	**test;
	int		i;

	i = 0;
	test = arg_tab(argc, argv);
	while (test[i])
	{
		printf("arg %d: %s\n", i, test[i]);
		i ++;
	}
	free_tab(test);
	return (0);
}
*/