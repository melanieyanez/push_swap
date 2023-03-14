/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:34:54 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/14 10:35:57 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char const *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		size ++;
	return (size);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	result = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i ++;
	}
	result[i] = '\0';
	return (result);
}

void	free_malloc(char **result, size_t i)
{
	size_t	j;

	j = 0;
	while (j <= i)
	{
		free(result[j]);
		j ++;
	}
}

size_t	nb_substr(char const *s, char c)
{
	size_t	i;
	size_t	nb;
	size_t	size;

	i = 0;
	nb = 0;
	size = ft_strlen(s);
	if (size == 0)
		return (0);
	if (s[i] != c)
		nb = 1;
	while (i < size - 1)
	{
		if (s[i] == c && s[i + 1] != c)
			nb ++;
		i ++;
	}
	return (nb);
}

char	*substr_gen(char const *s, char c, size_t *index)
{
	char	*sub_result;
	size_t	size;
	size_t	i;

	size = 0;
	while (s[*index] == c && s[*index])
		(*index)++;
	while (s[*index + size] && s[*index + size] != c)
		size ++;
	sub_result = malloc(sizeof(*s) * (size + 1));
	if (!sub_result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sub_result[i] = s[*index];
		i ++;
		(*index)++;
	}
	sub_result[i] = '\0';
	return (sub_result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**result;

	result = malloc((nb_substr(s, c) + 1) * sizeof(s));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_substr(s, c))
	{
		result[i] = substr_gen(s, c, &j);
		if (!result[i])
		{
			free_malloc(result, i);
			free(result);
			return (NULL);
		}
		i ++;
	}
	result[i] = 0;
	return (result);
}
