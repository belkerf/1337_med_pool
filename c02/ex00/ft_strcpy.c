/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:05:46 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/06/30 19:33:07 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*re;

	re = dest;
	while (*src != '\0')
	{
		*re = *src;
		re++;
		src++;
	}
	*re = '\0';
	return (dest);
}
