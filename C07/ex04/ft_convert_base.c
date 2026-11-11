/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:11:28 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/27 10:20:45 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base, int *size);

int	ft_sizeof(long nbr, int size)
{
	int	b;

	b = 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= size)
	{
		nbr /= size;
		b++;
	}
	return (b);
}

void	strev(char *str)
{
	char	box;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '-')
		i = 1;
	while (str[j] != '\0')
		j++;
	j--;
	while (i < j)
	{
		box = str[j];
		str[j] = str[i];
		str[i] = box;
		j--;
		i++;
	}
}

void	to_base(char *str, int size, long nb, char *base)
{
	int	m;

	m = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		m = 1;
	}
	while (nb >= size)
	{
		str[m] = base[nb % size];
		nb /= size;
		m++;
	}
	str[m] = base[nb % size];
	str[m + 1] = '\0';
	strev(str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	long	nb;
	int		size;
	int		sizel;
	int		b;

	size = 0;
	if (check_base(base_to, &size) == 0 || check_base(base_from, &sizel) == 0)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	if (nb == 0)
	{
		str = malloc(2);
		if (str == NULL)
			return (NULL);
		str[0] = base_to[0];
		str[1] = '\0';
		return (str);
	}
	b = ft_sizeof(nb, size);
	str = (char *)malloc((b + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	to_base(str, size, nb, base_to);
	return (str);
}
