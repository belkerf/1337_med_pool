/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:27:33 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/01 15:52:28 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*ma;
	int		l;

	ma = str;
	l = 'a' - 'A';
	while (*ma)
	{
		if (*ma >= 'A' && *ma <= 'Z')
		{
			*ma = *ma + l;
		}
		ma++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	char	*p;
	int		l;
	int		a;

	p = str;
	ft_strlowcase(p);
	a = 0;
	l = 'a' - 'A';
	while (*p)
	{
		if ((*p >= 'a' && *p <= 'z') && a == 0)
		{
			*p = *p - l;
			a++;
		}
		else if (!((*p >= 'a' && *p <= 'z') || (*p >= '0' && *p <= '9')))
			a = 0;
		else
			a++;
		p++;
	}
	return (str);
}
