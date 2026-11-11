/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 12:45:49 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/24 12:46:28 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	p = (int *)malloc((max - min) * sizeof(int));
	if (p == NULL)
		return (NULL);
	while (min < max)
	{
		p[i] = min;
		min++;
		i++;
	}
	return (p);
}
