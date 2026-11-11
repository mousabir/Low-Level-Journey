/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:50:20 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/05 20:54:31 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

void	print_error(void)
{
	write(1, "map error\n", 10);
}

int	check_unique(char a, char b, char c)
{
	if (a == b || a == c || b == c)
		return (0);
	if (a < 32 || b < 32 || c < 32)
		return (0);
	return (1);
}

int	init_grid(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * ((size_t)map->rows + 1));
	if (!map->grid)
		return (0);
	i = 0;
	while (i <= map->rows)
	{
		map->grid[i] = NULL;
		i++;
	}
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->grid)
	{
		while (map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}
