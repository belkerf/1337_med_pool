/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:22:16 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/13 19:22:51 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	l;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = max - min;
	range[0] = (int *)malloc(i * sizeof(int));
	l = 0;
	while (l < i && min < max)
	{
		range[0][l] = min;
		min++;
		l++;
	}
	return (i);
}
