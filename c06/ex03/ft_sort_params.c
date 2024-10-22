/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:14:11 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/10 10:15:15 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putarg(char *arg)
{
	while (*arg)
	{
		write(1, arg, 1);
		arg++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *arg1, char *arg2)
{
	int	i;

	i = 0;
	while (arg1[i] != '\0' && arg2[i] != '\0' && arg1[i] == arg2[i])
		i++;
	return (arg1[i] - arg2[i]);
}

void	swap(char **arg1, char **arg2)
{
	char	*s;

	s = *arg1;
	*arg1 = *arg2;
	*arg2 = s;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				swap(&argv[i], &argv[j]);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		putarg(argv[i]);
		i++;
	}
	return (0);
}
