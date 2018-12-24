/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:41:05 by alamorth          #+#    #+#             */
/*   Updated: 2018/12/23 23:23:17 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			ret;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			str++;
			ret += 1;
		}
		else
		{
			str++;
			i = ft_conv(str, ap, &ret);
			while (i-- > 0)
				str++;
		}
	}
	va_end(ap);
	return (ret);
}
