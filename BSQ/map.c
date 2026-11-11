/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:51:20 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/05 20:55:39 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	read_line(int fd, char **line, int *len, t_map *map)
{
	char	c;
	int		i;
	int		cap;
	int		ret;

	if (!init_line(line, &cap, &i))
		return (0);
	ret = read(fd, &c, 1);
	while (ret == 1 && c != '\n')
	{
		if (c != map->empty && c != map->obs)
			return (free(*line), 0);
		if (i >= cap - 1 && !expand_line(line, &cap, i))
			return (free(*line), 0);
		(*line)[i++] = c;
		ret = read(fd, &c, 1);
	}
	if (ret < 0 || (ret == 0 && i == 0))
		return (free(*line), 0);
	(*line)[i] = '\0';
	*len = i;
	return (1);
}

int	check_cols(int *cols, int len, char *line, t_map *map)
{
	if (*cols == -1)
		*cols = len;
	else if (len != *cols)
	{
		free(line);
		free_map(map);
		return (0);
	}
	return (1);
}

int	finish_map(int fd, t_map *map, int cols, int i)
{
	char	c;

	map->grid[i] = NULL;
	map->cols = cols;
	if (cols <= 0 || read(fd, &c, 1) != 0)
	{
		free_map(map);
		return (0);
	}
	return (1);
}

int	read_map(int fd, t_map *map)
{
	int		i;
	int		cols;
	char	*line;
	int		len;

	cols = -1;
	if (!init_grid(map))
		return (0);
	i = 0;
	while (i < map->rows)
	{
		if (!read_line(fd, &line, &len, map))
			return (free_map(map), 0);
		if (!check_cols(&cols, len, line, map))
			return (0);
		map->grid[i++] = line;
	}
	return (finish_map(fd, map, cols, i));
}
