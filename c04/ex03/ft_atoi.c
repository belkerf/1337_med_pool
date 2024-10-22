/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:01:39 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/03 22:35:01 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_helper(int *n, int *s, int a, char *str)
{
	int	k;

	k = 0;
	while (*str)
	{
		if (*str <= '9' && *str >= '0')
		{
			*n = (*n * 10) + *str - '0';
			a++;
			k++;
		}
		else if ((*str == ' ' || *str == '\t' || *str == '\n'
				|| *str == '\v' || *str == '\f' || *str == '\r') && a == 0)
			a = 0;
		else if ((*str == '-' || *str == '+') && k == 0)
		{
			if (*str == '-')
				*s = *s * (-1);
			a++;
		}
		else
			break ;
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	n;
	int	s;
	int	a;

	a = 0;
	n = 0;
	s = 1;
	ft_helper(&n, &s, a, str);
	return (n * s);
}
