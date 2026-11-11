/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:50:32 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/05 22:56:13 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	read_header_line(int fd, char **line, int *len)
{
	char	c;
	int		i;
	int		cap;

	if (!init_line(line, &cap, &i))
		return (0);
	while (read(fd, &c, 1) == 1)
	{
		if (c == '\n')
		{
			(*line)[i] = '\0';
			*len = i;
			return (1);
		}
		if (i >= cap - 1 && !expand_line(line, &cap, i))
			return (free(*line), 0);
		(*line)[i++] = c;
	}
	return (free(*line), 0);
}

int	parse_count(char *line, int len, t_map *map)
{
	long	rows;
	int		i;

	if (len < 4)
		return (0);
	map->empty = line[len - 3];
	map->obs = line[len - 2];
	map->full = line[len - 1];
	rows = 0;
	i = 0;
	while (i < len - 3)
	{
		if (!is_digit(line[i]))
			return (0);
		if (rows > 214748364 || (rows == 214748364 && line[i] > '7'))
			return (0);
		rows = rows * 10 + (line[i] - '0');
		i++;
	}
	if (rows <= 0)
		return (0);
	map->rows = (int)rows;
	return (check_unique(map->empty, map->obs, map->full));
}

int	get_rows(int fd, t_map *map)
{
	char	*line;
	int		len;
	int		ok;

	if (!read_header_line(fd, &line, &len))
		return (0);
	ok = parse_count(line, len, map);
	free(line);
	return (ok);
}

int	parse_header(int fd, t_map *map)
{
	return (get_rows(fd, map));
}
