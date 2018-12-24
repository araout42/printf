/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:37:14 by araout            #+#    #+#             */
/*   Updated: 2018/12/23 22:40:13 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_oct(unsigned long long nbr, int **ret)
{
	char	*base;
	int		i;
	char	res[32];

	base = "01234567";
	i = 31;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		**ret += 1;
	}
	while (nbr > 0)
	{
		res[i] = base[(nbr % 8)];
		nbr /= 8;
		i--;
		**ret += 1;
	}
	while (++i < 32)
		ft_putchar(res[i]);
}
