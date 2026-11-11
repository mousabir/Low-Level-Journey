/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:50:58 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/05 20:55:14 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			write(1, &map->grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	process_file(int fd)
{
	t_map		map;
	t_square	best;
	int			is_stdin;

	map.grid = NULL;
	map.rows = 0;
	map.cols = 0;
	is_stdin = (fd == 0);
	if (!parse_header(fd, &map) || !read_map(fd, &map))
	{
		print_error();
		if (!is_stdin)
			close(fd);
		return ;
	}
	best = find_largest_square(&map);
	fill_grid(&best, &map);
	print_map(&map);
	free_map(&map);
	if (!is_stdin)
		close(fd);
}

void	open_and_process(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		print_error();
		return ;
	}
	process_file(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		process_file(0);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (i > 1)
			write(1, "\n", 1);
		open_and_process(argv[i]);
		i++;
	}
	return (0);
}
