/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 19:30:31 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/23 19:30:46 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		argc--;
		while (argc > 0)
		{
			i = 0;
			while (argv[argc][i] != '\0')
			{
				write(1, &argv[argc][i], 1);
				i++;
			}
			write(1, "\n", 1);
			argc--;
		}
	}
	else
		return (0);
}
