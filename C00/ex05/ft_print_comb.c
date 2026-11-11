/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 18:39:33 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/14 18:39:38 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	ind_0;
	char	ind_1;
	char	ind_2;

	ind_0 = '0';
	while (ind_0 <= '7')
	{
		ind_1 = ind_0 + 1;
		while (ind_1 <= '8')
		{
			ind_2 = ind_1 + 1;
			while (ind_2 <= '9')
			{
				write(1, &ind_0, 1);
				write(1, &ind_1, 1);
				write(1, &ind_2, 1);
				if (!(ind_0 == '7' && ind_1 == '8' && ind_2 == '9'))
					write(1, ", ", 2);
				ind_2++;
			}
			ind_1++;
		}
		ind_0++;
	}
}
