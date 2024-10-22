/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:53:34 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/06/30 16:41:03 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int a, int b)
{
	int		i;
	int		j;

	i = 0;
	while (i < b)
	{
		j = 0;
		while (j < a)
		{
			if ((i == b - 1 || i == 0) && (j == a - 1 || j == 0))
				ft_putchar('o');
			else if (i == 0 || i == b - 1)
				ft_putchar('-');
			else if (j == 0 || j == a - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
