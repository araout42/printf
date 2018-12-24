/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:49:39 by araout            #+#    #+#             */
/*   Updated: 2018/12/23 22:56:34 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_base(char c)
{
	if (c == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

void			ft_putnbr_hexa(unsigned long nbr, char c, int **ret)
{
	char	*base;
	int		i;
	char	res[32];

	i = 31;
	base = get_base(c);
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		**ret += 1;
	}
	while (nbr > 0)
	{
		res[i] = base[nbr % 16];
		nbr /= 16;
		i--;
		**ret += 1;
	}
	if (c == 'p')
	{
		write(1, "0x", 2);
		**ret += 2;
	}
	while (++i < 32)
		ft_putchar(res[i]);
}
