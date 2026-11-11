/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:18:46 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/04 08:28:11 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (sign % 2 != 0)
		return (nbr * -1);
	return (nbr);
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
	char	arr[12];
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

int	chek_error(int nbr, char op)
{
	if (nbr == 0 && op == '/')
	{
		write(2, "Stop : division by zero\n", 24);
		return (1);
	}
	else if (nbr == 0 && op == '%')
	{
		write(2, "Stop : modulo by zero\n", 22);
		return (1);
	}
	else
		return (0);
}

void	print_out(int nb, int nbr, int (*f[])(int, int), char *str)
{
	char	*op;
	int		i;

	i = 0;
	op = "+-*/%";
	while (i < 5)
	{
		if (str[0] == op[i] && str[1] == '\0')
		{
			ft_putnbr(f[i](nb, nbr));
			break ;
		}
		i++;
	}
	if (i == 5)
		ft_putnbr(0);
}
