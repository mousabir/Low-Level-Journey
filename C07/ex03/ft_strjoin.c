/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:51:35 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/27 10:17:37 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	conter_word(char **str, char *sep, int size)
{
	int	j;
	int	i;
	int	size1;
	int	m;

	size1 = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			size1++;
			j++;
		}
		i++;
	}
	m = 0;
	while (sep[m] != '\0')
		m++;
	return (size1 + (size - 1) * m);
}

void	apend_word(char *sep, char **strs, char *str, int size)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	b = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[b] = strs[i][j];
			b++;
			j++;
		}
		i++;
		j = 0;
		while (sep[j] != '\0' && i < size)
		{
			str[b] = sep[j];
			b++;
			j++;
		}
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		sizeo;

	if (size == 0)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	sizeo = conter_word(strs, sep, size);
	str = malloc((sizeo + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	apend_word(sep, strs, str, size);
	str[sizeo] = '\0';
	return (str);
}
