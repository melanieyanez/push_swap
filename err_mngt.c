/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_mngt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:07:02 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/10 18:00:24 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Remplacer les conditions par la fct is_digit */
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
				return (0);
		}
		while (args[i][j])
		{
			if (args[i][j] < 48 || args[i][j] > 57)
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

/*
int	main(int argc, char **argv)
{
	char	**test;

	test = arg_tab(argc, argv);
	if (check_number(test) == 0)
		printf("Un des arguments n'est pas un nombre");
	else
		printf("au top");
	return (0);
}
*/

/*
int	check_int(char **args)
{
	
}
*/

/* à vérifier une fois qu'ils sont en int */

/*
int	check_double(char **args)
{
	
}
*/

/*
void	err_msg(char **args)
{
	if (check_number(args) == 0
		|| check_int(args) == 0
		|| check_double(args) == 0)
		write(2, "Error\n", 6);
}
*/