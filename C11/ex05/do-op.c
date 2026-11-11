/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:16:23 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/03 18:00:22 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "do_op.h"

int	main(int argc, char *argv[])
{
	int	nb ;
	int	nbr;
	int	(*f[5])(int, int);

	f[0] = &add;
	f[1] = &sub;
	f[2] = &mul;
	f[3] = &divide;
	f[4] = &mod;
	if (argc == 4)
	{
		nb = ft_atoi(argv[1]);
		nbr = ft_atoi(argv[3]);
		if (chek_error(nbr, argv[2][0]) == 0)
		{
			print_out(nb, nbr, f, argv[2]);
			write(1, "\n", 1);
			return (0);
		}
	}
	return (0);
}
