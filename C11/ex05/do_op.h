/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousabir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:57:04 by mousabir          #+#    #+#             */
/*   Updated: 2026/08/03 17:59:26 by mousabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		divide(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
void	revr_nb(char arr[], int j);
void	ft_putnbr(int nb);
void	print_out(int nb, int nbr, int (*f[])(int, int), char *str);

int		chek_error(int nbr, char op);

#endif
