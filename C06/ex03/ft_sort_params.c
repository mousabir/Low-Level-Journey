/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:31:36 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/25 15:19:41 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_par(char **str, int nb)
{
	int	i;
	int	use_m;

	i = 1;
	while (i < nb)
	{
		use_m = 0;
		while (str[i][use_m] != '\0')
		{
			write(1, &str[i][use_m], 1);
			use_m++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int argc, char *argv[])
{
	char	*box;
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				box = argv[i];
				argv[i] = argv[j];
				argv[j] = box;
			}
			j++;
		}
		i++;
	}
	print_par(argv, argc);
}
