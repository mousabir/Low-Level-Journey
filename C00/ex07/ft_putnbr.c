/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 21:44:51 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/14 21:59:29 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
