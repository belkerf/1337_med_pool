/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:51:15 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/13 18:18:43 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
void	put_base(long int nb, char *base, char *re);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
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
	return (1);
}

int	ft_helper(char *str, char *base, int len, int s)
{
	int	n;
	int	k;
	int	f;

	n = 0;
	while (*str)
	{
		k = 0;
		f = 0;
		while (base[k])
		{
			if (*str == base[k])
			{
				n = (n * len) + k;
				f = 1;
			}
			k++;
		}
		if (f == 0)
			return (s * n);
		str++;
	}
	return (n * s);
}

int	turn(char *str, char *base, int len)
{
	int	n;
	int	s;

	n = 0;
	s = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = s * (-1);
		str++;
	}
	return (ft_helper(str, base, len, s));
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	ln;
	int	len;

	ln = ft_strlen(str);
	len = ft_strlen(base);
	i = check_base(base);
	if (i != 0)
	{
		return (turn(str, base, len));
	}
	return (0);
}
