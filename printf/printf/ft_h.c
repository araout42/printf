/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:44:09 by araout            #+#    #+#             */
/*   Updated: 2018/12/24 07:41:43 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		is_h(const char *str, va_list ap, int **ret)
{
	if (*str == 'd' || *str == 'i')
		ft_putnbr_long((signed char)va_arg(ap, int), ret);
	else if (*str == 'o')
		ft_putnbr_oct((signed char)(va_arg(ap, int)), ret);
	else if (*str == 'u')
		ft_putnbr_unsigned((signed char)(va_arg(ap, int)), ret);
	else if (*str == 'x' || *str == 'X')
		ft_putnbr_hexa((signed char)(va_arg(ap, int)), *str, ret);
	else if (*str == 'f')
		itoafloat((double)(va_arg(ap, double)), ret);
}

void			ft_h(const char *str, va_list ap, int *i, int **ret)
{
	str++;
	if (*str == 'h')
	{
		str++;
		is_h(str, ap, ret);
		*i += 2;
	}
	else
	{
		if (*str == 'd' || *str == 'i')
			ft_putnbr_long((short int)va_arg(ap, unsigned int), ret);
		else if (*str == 'o')
			ft_putnbr_oct((short int)(va_arg(ap, unsigned int)), ret);
		else if (*str == 'u')
			ft_putnbr_unsigned((short int)(va_arg(ap, unsigned int)), ret);
		else if (*str == 'x' || *str == 'X')
			ft_putnbr_hexa((short int)(va_arg(ap, unsigned int)), *str, ret);
		else if (*str == 'f')
			itoafloat((double)(va_arg(ap, double)), ret);
		*i += 1;
	}
}
