/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:07:01 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/03 14:10:14 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	re;

	i = 0;
	if (power < 0)
		return (0);
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		re = nb;
		while (i < power - 1)
		{
			nb = nb * re;
			i++;
		}
		return (nb);
	}
}
