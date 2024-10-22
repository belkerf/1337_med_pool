/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:35:48 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/14 13:55:22 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	isset(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_co(char *str, char *set)
{
	int	co;

	co = 0;
	while (*str)
	{
		while (isset(*str, set) && *str)
			str++;
		if (*str)
			co++;
		while (!isset(*str, set) && *str)
			str++;
		if (*str)
			str++;
	}
	return (co);
}

int	*co_el(int co, char *str, char *set, int i)
{
	int	*tab;

	tab = (int *)malloc(co * sizeof(int));
	co = -1;
	while (*str)
	{
		while (isset(*str, set) && *str)
			str++;
		if (*str)
		{
			co++;
			i = 0;
		}
		while (!isset(*str, set) && *str)
		{
			str++;
			i++;
		}
		tab[co] = i + 1;
	}
	return (tab);
}

char	**mv(char **re, char *str, char *set, int co)
{
	int	i;
	int	j;

	i = -1;
	while (*str && i < co)
	{
		while (isset(*str, set) && *str)
			str++;
		if (*str)
		{
			i++;
			j = 0;
		}
		while (!isset(*str, set) && *str)
		{
			re[i][j] = *str;
			str++;
			j++;
		}
		re[i][j] = '\0';
	}
	i++;
	re[i] = NULL;
	return (re);
}

char	**ft_split(char *str, char *charset)
{
	char	**re;
	int		*tab;
	int		co;
	int		i;

	i = 0;
	co = word_co(str, charset);
	co++;
	re = (char **)malloc((co) * sizeof(char *));
	tab = co_el(co, str, charset, i);
	while (i < co - 1)
	{
		re[i] = (char *)malloc(tab[i] * sizeof(char));
		i++;
	}
	re[i] = (char *)malloc(1 * sizeof(char));
	re = mv(re, str, charset, co);
	return (re);
}
