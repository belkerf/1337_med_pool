/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:21:32 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/06/29 14:24:38 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		l;
	char	*result;

	result = str;
	l = 'a' - 'A';
	while (*result)
	{
		if (*result >= 'a' && *result <= 'z')
		{
			*result = *result - l;
		}
		result++;
	}
	return (str);
}
