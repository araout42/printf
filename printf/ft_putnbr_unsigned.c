/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:40:48 by araout            #+#    #+#             */
/*   Updated: 2018/12/23 22:41:12 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_unsigned(unsigned int nbr, int **ret)
{
	int		a;

	a = nbr;
	if (a < 0)
		ft_putnbr_long(4294967296 + a, ret);
	else
		ft_putnbr_long(a, ret);
}
