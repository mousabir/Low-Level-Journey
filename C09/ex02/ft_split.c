/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:03:10 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/28 14:19:44 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *cher)
{
	int	i;

	i = 0;
	while (cher[i] != '\0')
	{
		if (cher[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	conter;

	conter = 0;
	i = 0;
	while (str[i])
	{
		while ((is_sep(str[i], sep) == 1) && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			return (conter);
		conter++;
		while ((is_sep(str[i], sep) == 0) && str[i] != '\0')
			i++;
	}
	return (conter);
}

char	*git_word(char *str, int len)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	cpy_words(char **s, char *str, char *charset)
{
	int	j;
	int	index;
	int	st;

	j = 0;
	index = 0;
	while (str[j])
	{
		while (str[j] && is_sep(str[j], charset))
			j++;
		if (str[j] == '\0')
			break ;
		st = j;
		while (str[j] && !is_sep(str[j], charset))
			j++;
		s[index] = git_word(&str[st], j - st);
		if (s[index] == NULL)
			return (0);
		index++;
	}
	s[index] = NULL;
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**s;

	s = malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (s == NULL)
		return (NULL);
	if (cpy_words(s, str, charset) == 0)
		return (NULL);
	return (s);
}
