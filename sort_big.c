/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:37:50 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/15 18:04:28 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Algo pour trier un grand nombre de nombres */

/* Retourne la position du plus petit nombre dans la première moitié de la liste */
/* Quand on a deux chunk */
/* Réfléchir au nombre de chunk */

int	nbr_chunk(t_list *li)
{
	int	size;
	int	nbr_chunk;

	size = list_length(*li);
	if (size > 5 && size <= 100)
		nbr_chunk = 5;
	return (nbr_chunk);
}

/* scan from top fonctionne, scan_from_bottom pas */

int	scan_from_top(char **args, long *args_i, int nbr_chunk)
{
	int		i;
	long	min;
	int		min_pos;
	int		size;

	size = tab_len(args);
	i = 0;
	min = args_i[0];
	while (i < (size / nbr_chunk))
	{
		++ i;
		if (args_i[i] < min)
		{
			min = args_i[i];
			min_pos = i;
		}
	}
	return (min_pos);
}

int	scan_from_bottom(char **args, long *args_i, int nbr_chunk)
{
	int		i;
	long	min;
	int		min_pos;
	int		size;

	size = tab_len(args);
	i = size;
	min = args_i[size - 1];
	while (i > (size - (size / nbr_chunk)))
	{
		if (args_i[i] < min)
		{
			min = args_i[i];
			min_pos = i;
		}
		i --;
	}
	return (min_pos);
}

int	main(int argc, char **argv)
{
	char	**args;
	long	*args_i;
	int		i;
	t_list	list_a;
	t_list	list_b;

	args = arg_tab(argc, argv);
	args_i = char_to_long(args);
	printf(" Le minimum depuis le haut avec 2 chunks : %ld\n", args_i[scan_from_top(args, args_i, 2)]);
	printf(" Le minimum depuis le haut avec 2 chunks : %ld\n", args_i[scan_from_bottom(args, args_i, 2)]);
	return (0);
}
