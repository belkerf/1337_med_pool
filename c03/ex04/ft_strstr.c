/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:55:29 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/07 19:07:12 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*tp;
	int		i;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		i = 0;
		if (*str == to_find[0])
		{
			tp = str;
			while (to_find[i] && *str)
			{
				if (*str != to_find[i])
					break ;
				i++;
				str++;
			}
			if (to_find[i] == '\0')
				return (tp);
			str = tp;
		}
		str++;
	}
	return (0);
}
