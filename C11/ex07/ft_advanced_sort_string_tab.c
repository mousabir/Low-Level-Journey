/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:09:00 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/06 08:18:29 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*tmp;
	int		swapped;
	int		i;

	if (!tab || !cmp)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 1;
		while (tab[i])
		{
			if (cmp(tab[i - 1], tab[i]) > 0)
			{
				tmp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}
