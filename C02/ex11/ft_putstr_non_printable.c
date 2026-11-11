/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 21:01:42 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/21 18:30:59 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	to_hex_base(unsigned int nbr)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[nbr / 16], 1);
	write(1, &hex[nbr % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] < 32 || (unsigned char)str[i] >= 127)
		{
			write(1, "\\", 1);
			to_hex_base((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
