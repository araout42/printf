/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:59:18 by araout            #+#    #+#             */
/*   Updated: 2018/12/24 06:57:05 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		is_l(const char *str, va_list ap, int **ret)
{
	if (*str == 'd' || *str == 'i')
		ft_putnbr_long((long long int)va_arg(ap, long long int), ret);
	else if (*str == 'o')
		ft_putnbr_oct((long long int)(va_arg(ap, long long int)), ret);
	else if (*str == 'u')
		ft_putnbr_unsigned((long long int)(va_arg(ap, long long int)), ret);
	else if (*str == 'x' || *str == 'X')
		ft_putnbr_hexa((long long int)(va_arg(ap, long long int)), *str, ret);
	else if (*str == 'f')
	{
		itoafloat((double)(va_arg(ap, double)), ret);
		str++;
	}
}

void			ft_l(const char *str, va_list ap, int *i, int **ret)
{
	str++;
	if (*str == 'l')
	{
		str++;
		is_l(str, ap, ret);
		*i += 2;
	}
	else
	{
		if (*str == 'd' || *str == 'i')
			ft_putnbr_long((long int)va_arg(ap, long int), ret);
		else if (*str == 'o')
			ft_putnbr_oct((long int)(va_arg(ap, long int)), ret);
		else if (*str == 'u')
			ft_putnbr_unsigned((long int)(va_arg(ap, long int)), ret);
		else if (*str == 'x' || *str == 'X')
			ft_putnbr_hexa((long int)(va_arg(ap, long int)), *str, ret);
		else if (*str == 'f')
		{
			itoafloat((double)(va_arg(ap, double)), ret);
			str++;
		}
		*i += 1;
	}
}
