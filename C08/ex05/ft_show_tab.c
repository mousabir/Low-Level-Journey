/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:54:05 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/27 18:54:11 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	if (*str)
	{
		write(1, str, 1);
		ft_putstr(str + 1);
	}
}

void	revr_nb(char arr[], int j)
{
	char	box;
	int		i;
	int		m;

	i = 0;
	m = 0;
	j--;
	while (i < j)
	{
		box = arr[i];
		arr[i] = arr[j];
		arr[j] = box;
		i++;
		j--;
	}
	while (arr[m] != '\0')
	{
		write(1, &arr[m], 1);
		m++;
	}
}

void	ft_putnbr(int nb)
{
	char	arr[11];
	int		index;
	long	nbr;

	nbr = nb;
	index = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		arr[index] = '0' + (nbr % 10);
		nbr = nbr / 10;
		index++;
	}
	arr[index] = '\0';
	revr_nb(arr, index);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
