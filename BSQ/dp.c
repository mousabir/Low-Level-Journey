/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:50:09 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/05 20:54:06 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

void	free_dp(int **dp, int rows)
{
	int	r;

	r = 0;
	while (r < rows)
	{
		free(dp[r]);
		r++;
	}
	free(dp);
}

int	**create_dp(int cols, int rows)
{
	int	**dp;
	int	r;

	dp = malloc(sizeof(int *) * (size_t)rows);
	if (dp == NULL)
		return (NULL);
	r = 0;
	while (r < rows)
	{
		dp[r] = malloc(sizeof(int) * (size_t)cols);
		if (dp[r] == NULL)
		{
			free_dp(dp, r);
			return (NULL);
		}
		r++;
	}
	return (dp);
}
