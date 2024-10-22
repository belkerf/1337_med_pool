/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:23:16 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/13 20:05:19 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	strl(char **strs, int size)
{
	int	i;
	int	s_strs;

	s_strs = 0;
	i = 0;
	while (i < size)
	{
		s_strs = s_strs + (ft_strlen(strs[i]));
		i++;
	}
	return (s_strs);
}

char	*stcp(char *sep, char **strs, int size, char *res)
{
	int		k;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
		{
			res[j] = strs[i][k];
			k++;
			j++;
		}
		k = 0;
		while (sep[k++] && i < size - 1)
		{
			res[j] = sep[k - 1];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		s_sep;
	int		s_strs;
	int		s_res;

	s_sep = (ft_strlen(sep) - 1) * (size - 1);
	s_strs = strl(strs, size);
	s_strs++;
	s_res = s_strs + s_sep * (size - 1);
	res = (char *)malloc(s_res * sizeof(char));
	res = stcp(sep, strs, size, res);
	return (res);
}
