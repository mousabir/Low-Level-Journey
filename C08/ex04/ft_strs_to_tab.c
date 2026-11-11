/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:21:12 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/27 18:22:15 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	fre_memory(struct s_stock_str *p, int i)
{
	if (i >= 0)
	{
		free(p[i].copy);
		fre_memory(p, i - 1);
	}
	return ;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*p;
	int			i;

	p = malloc((ac + 1) * sizeof(t_stock_str));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		p[i].size = ft_strlen(av[i]);
		p[i].str = av[i];
		p[i].copy = ft_strdup(av[i]);
		if (p[i].copy == NULL)
		{
			fre_memory(p, i);
			free(p);
			return (NULL);
		}
		i++;
	}
	p[ac].size = 0;
	p[ac].str = NULL;
	p[ac].copy = NULL;
	return (p);
}
