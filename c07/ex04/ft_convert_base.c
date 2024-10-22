/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:47:11 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/13 18:16:04 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	turn(char *str, char *base, int len);
int	ft_helper(char *str, char *base, int len, int s);
int	ft_strlen(char *str);
int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);

char	*strr(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = ft_strlen(str);
	len--;
	while (i <= len / 2)
	{
		c = str[i];
		str[i] = str[len - i];
		str[len - i] = c;
		i++;
	}
	return (str);
}

void	put_base(long int nb, char *base, char *re)
{
	int		i;
	int		len;
	int		f;

	f = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		f = 1;
	}
	i = 0;
	len = ft_strlen(base);
	while (nb >= len)
	{
		re[i] = base[nb % len];
		i++;
		nb = nb / len; 
	}
	re[i] = base[nb];
	i++;
	if (f == 1)
		re[i++] = '-';
	re[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			i;
	long int	n;
	char		*re;

	i = check_base(base_from);
	if (i == 0)
		return (0);
	i = check_base(base_to);
	if (i == 0)
		return (0);
	re = (char *)malloc(266 * sizeof(char));
	n = ft_atoi_base(nbr, base_from);
	i = 0;
	put_base(n, base_to, re);
	return (strr(re));
}
