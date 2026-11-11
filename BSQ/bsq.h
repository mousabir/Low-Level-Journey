/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:49:54 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/05 20:53:49 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	char	empty;
	char	obs;
	char	full;
}	t_map;

typedef struct s_square
{
	int	col;
	int	row;
	int	size;
}	t_square;

int			parse_header(int fd, t_map *map);
int			get_rows(int fd, t_map *map);
int			expand_line(char **line, int *cap, int len);
int			read_map(int fd, t_map *map);
int			read_line(int fd, char **line, int *len, t_map *map);
int			init_line(char **line, int *cap, int *i);
int			check_cols(int *cols, int len, char *line, t_map *map);
int			finish_map(int fd, t_map *map, int cols, int i);
int			init_grid(t_map *map);
int			check_unique(char a, char b, char c);
int			min3(int a, int b, int c);
int			**create_dp(int cols, int rows);
void		free_dp(int **dp, int rows);
t_square	find_largest_square(t_map *map);
void		fill_grid(t_square *best, t_map *map);
void		print_map(t_map *map);
void		print_error(void);
void		free_map(t_map *map);
void		process_file(int fd);

#endif
