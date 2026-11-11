/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:51:31 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/05 20:56:32 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	min3(int a, int b, int c)
{
	if (a <= b)
	{
		if (a <= c)
			return (a);
		return (c);
	}
	if (b <= c)
		return (b);
	return (c);
}

int	cell_value(t_map *map, int **dp, int i, int j)
{
	if (map->grid[i][j] == map->obs)
		return (0);
	if (i == 0 || j == 0)
		return (1);
	return (1 + min3(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]));
}

void	scan_row(t_map *map, int **dp, int i, t_square *best)
{
	int	j;

	j = 0;
	while (j < map->cols)
	{
		dp[i][j] = cell_value(map, dp, i, j);
		if (dp[i][j] > best->size)
		{
			best->size = dp[i][j];
			best->row = i;
			best->col = j;
		}
		j++;
	}
}

t_square	find_largest_square(t_map *map)
{
	t_square	best;
	int			**dp;
	int			i;

	best.size = 0;
	best.row = 0;
	best.col = 0;
	dp = create_dp(map->cols, map->rows);
	if (dp == NULL)
		return (best);
	i = 0;
	while (i < map->rows)
	{
		scan_row(map, dp, i, &best);
		i++;
	}
	free_dp(dp, map->rows);
	return (best);
}

void	fill_grid(t_square *best, t_map *map)
{
	int	start_row;
	int	start_col;
	int	r;
	int	c;

	start_row = best->row - best->size + 1;
	start_col = best->col - best->size + 1;
	r = start_row;
	while (r <= best->row)
	{
		c = start_col;
		while (c <= best->col)
		{
			map->grid[r][c] = map->full;
			c++;
		}
		r++;
	}
}
