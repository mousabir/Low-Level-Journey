/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:10:10 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/03 10:25:36 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ordr;

	i = 0;
	if (length <= 1)
		return (1);
	while (i < length - 1 && f(tab[i], tab[i + 1]) == 0)
		i++;
	if (i == length - 1)
		return (1);
	ordr = f(tab[i], tab[i + 1]);
	while (i < length - 1)
	{
		if (ordr > 0 && f(tab[i], tab[i + 1]) < 0)
			return (0);
		if (ordr < 0 && f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
