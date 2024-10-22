/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:25:20 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/07 19:15:56 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = ft_strlen(src);
	k = ft_strlen(dest);
	if (size == 0)
		return (i);
	else if (size < k)
		return (size + i);
	else
	{
		j = 0;
		while (*dest)
			dest++;
		while (k + j < size - 1 && src[j])
		{
			*dest = src[j];
			j++;
			dest++;
		}
		*dest = '\0';
	}
	return (i + k);
}
