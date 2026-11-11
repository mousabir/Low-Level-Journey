/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:50:43 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/05 20:54:52 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	init_line(char **line, int *cap, int *i)
{
	*i = 0;
	*cap = 64;
	*line = malloc(*cap);
	if (!*line)
		return (0);
	return (1);
}

int	expand_line(char **line, int *cap, int len)
{
	char	*tmp;
	int		i;

	if (*cap > 1073741823)
		return (0);
	*cap *= 2;
	tmp = malloc(*cap);
	if (!tmp)
		return (0);
	i = 0;
	while (i < len)
	{
		tmp[i] = (*line)[i];
		i++;
	}
	free(*line);
	*line = tmp;
	return (1);
}
