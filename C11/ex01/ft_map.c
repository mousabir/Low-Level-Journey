/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:42:08 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/01 18:44:57 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*p;

	p = malloc(length * sizeof(int));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		p[i] = (*f)(tab[i]);
		i++;
	}
	return (p);
}
