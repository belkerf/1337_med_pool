/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:41:07 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/06/27 16:56:50 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;
	int		nbr1;

	if (nb >= 0 && nb <= 9)
	{
		c = nb + '0';
		write(1, "0", 1);
		write(1, &c, 1);
	}
	else if (nb >= 10 && nb <= 99)
	{
		nbr1 = nb / 10;
		c = nbr1 + '0';
		write(1, &c, 1);
		nbr1 = nb % 10;
		c = nbr1 + '0';
		write(1, &c, 1);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putnbr(a);
			write(1, " ", 1);
			ft_putnbr(b);
			if (a == 98 && b == 99)
				break ;
			write(1, ",", 1);
			write(1, " ", 1);
			b++;
		}
		a++;
	}
}
