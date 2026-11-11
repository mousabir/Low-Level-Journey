/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:12:32 by mousabir          #+#    #+#             */
/*   Updated: 2026/07/25 21:13:04 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base, int *size)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13)
			|| base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	*size = i;
	return (1);
}

int	get_index(char t, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == t)
			return (i);
		i++;
	}
	return (-1);
}

int	clean_str(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			(*sign)++;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	r;
	int	size;
	int	sign;
	int	index;
	int	i;

	r = 0;
	sign = 0;
	if (check_base(base, &size) == 0)
		return (0);
	index = clean_str(str, &sign);
	i = get_index(str[index], base);
	while (i != -1 && str[index] != '\0')
	{
		r = r * size + i;
		index++;
		i = get_index(str[index], base);
	}
	if (sign % 2 != 0)
		return (-r);
	return (r);
}
