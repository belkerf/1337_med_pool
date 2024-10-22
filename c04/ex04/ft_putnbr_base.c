/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:03 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/13 10:56:32 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_base(char *base)
{
	int	len;
	int	i;
	int	k;

	len = ft_strlen(base);
	i = 0;
	if (len <= 1)
		return (0);
	while (i < len)
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		k = i - 1;
		while (k >= 0)
		{
			if (base[i] == base[k])
				return (0);
			k--;
		}
		i++;
	}
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_base(long int nb, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (nb < len)
	{
		ft_putchar(base[nb]);
	}
	else
	{
		put_base(nb / len, base);
		ft_putchar(base[nb % len]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	i;
	long int	n;

	n = nbr;
	i = check_base(base);
	if (i != 0)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * (-1);
		}
		put_base(n, base);
	}
}
