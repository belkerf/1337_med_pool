/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:36:10 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/03 20:44:33 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hexa(unsigned char not_h)
{
	char	*st;

	st = "0123456789abcdef";
	ft_putchar(st[not_h / 16]);
	ft_putchar(st[not_h % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str >= ' ' && *str <= '~')
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			print_hexa(*str);
		}
		str++;
	}
}
