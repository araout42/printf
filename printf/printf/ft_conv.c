/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 23:15:00 by araout            #+#    #+#             */
/*   Updated: 2018/12/24 07:30:36 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		ft_letter_check(const char *str, va_list ap, int *ret, int *i)
{
	if (*str == 'h')
		ft_h(str, ap, i, &ret);
	else if (*str == 'l')
		ft_l(str, ap, i, &ret);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_long(va_arg(ap, int), &ret);
	else if (*str == 'c')
	{
		*ret += 1;
		ft_putchar(va_arg(ap, int));
	}
	else if (*str == 's')
		ft_putstr_i(va_arg(ap, char *), &ret);
	else if (*str == 'p')
		ft_putnbr_hexa((unsigned long)(va_arg(ap, long)), *str, &ret);
	else if (*str == 'o')
		ft_putnbr_oct((unsigned int)(va_arg(ap, unsigned int)), &ret);
	else if (*str == 'u')
		ft_putnbr_unsigned((unsigned int)(va_arg(ap, unsigned int)), &ret);
	else if (*str == 'x' || *str == 'X')
		ft_putnbr_hexa((unsigned int)(va_arg(ap, unsigned int)), *str, &ret);
	else if (*str == 'f')
		itoafloat((double)(va_arg(ap, double)), &ret);
}

int				ft_conv(const char *str, va_list ap, int *ret)
{
	int		i;

	i = 0;
	ft_letter_check(str, ap, ret, &i);
	if (*str == '%')
	{
		*ret += 1;
		ft_putchar(*str);
	}
	else if (*str == '#')
		ft_twitter(str, &i, ap, &ret);
	str++;
	i += 1;
	return (i);
}
