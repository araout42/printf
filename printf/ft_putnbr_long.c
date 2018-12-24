/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:39:00 by araout            #+#    #+#             */
/*   Updated: 2018/12/23 22:39:40 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_long(int long long nb, int **ret)
{
	long long int nbr;

	nbr = nb;
	if (nb < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 10)
	{
		ft_putnbr_long(nbr / 10, ret);
	}
	**ret += 1;
	ft_putchar(nbr % 10 + '0');
}
