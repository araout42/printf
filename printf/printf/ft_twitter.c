/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twitter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 23:13:08 by araout            #+#    #+#             */
/*   Updated: 2018/12/23 23:13:36 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_twitter(const char *str, int *i, va_list ap, int **ret)
{
	str++;
	if (*str == 'o')
	{
		write(1, "0", 1);
		**ret += 1;
		ft_putnbr_oct((unsigned int)(va_arg(ap, unsigned int)), ret);
	}
	if (*str == 'x')
	{
		write(1, "0x", 2);
		**ret += 2;
		ft_putnbr_hexa((unsigned long)(va_arg(ap, long)), *str, ret);
	}
	if (*str == 'X')
	{
		write(1, "0X", 2);
		**ret += 2;
		ft_putnbr_hexa((unsigned long)(va_arg(ap, long)), *str, ret);
	}
	*i += 1;
}
