/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:08:55 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/23 17:11:37 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2 ;
	if (nb < 2)
		return (0);
	while (i < nb - 1)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	r;
	int	i;

	i = 0;
	if (nb < 2)
		nb = 2;
	while (42)
	{
		r = ft_is_prime(nb + i);
		if (r == 1)
			return (nb + i);
		i++;
	}
	return (0);
}
