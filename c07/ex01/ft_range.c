/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:21:29 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/07/13 19:21:54 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	l;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	i = max - min;
	arr = (int *)malloc(i * sizeof(int));
	l = 0;
	while (l < i && min < max)
	{
		arr[l] = min;
		min++;
		l++;
	}
	return (arr);
}
