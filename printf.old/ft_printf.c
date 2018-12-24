/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:41:05 by alamorth          #+#    #+#             */
/*   Updated: 2018/12/13 06:09:50 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void		itoafloat(double nbr, int **ret);
void		ft_putchar(char c);
size_t		ft_strlen(const char *str);
void		ft_putstr_i(char const *s, int **ret);

void		ft_putnbr_hexa(unsigned long nbr, char c, int **ret)
{
	char	*base;
	int		i;
	char	res[32];

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 31;
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

void		ft_putnbr_unsigned(unsigned int nbr, int **ret)
{
	int		a;

	a = nbr;
	if (a < 0)
		ft_putnbr_long(4294967296 + a, ret);
	else
		ft_putnbr_long(a, ret);
}

void		ft_h(const char *str, va_list ap, int *i, int **ret)
{
	str++;
	if (*str == 'h')
	{
		str++;
		if (*str == 'd' || *str == 'i')
			ft_putnbr_long((signed char)va_arg(ap, int), ret);
		else if (*str == 'o')
			ft_putnbr_oct((signed char)(va_arg(ap, int)), ret);
		else if (*str == 'u')
			ft_putnbr_unsigned((signed char)(va_arg(ap, int)), ret);
		else if (*str == 'x' || *str == 'X')
			ft_putnbr_hexa((signed char)(va_arg(ap, int)), *str, ret);
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
		*i += 1;
	}
}

void		ft_l(const char *str, va_list ap, int *i, int **ret)
{
	str++;
	if (*str == 'l')
	{
		str++;
		if (*str == 'd' || *str == 'i')
			ft_putnbr_long((long long int)va_arg(ap, long long int), ret);
		else if (*str == 'o')
			ft_putnbr_oct((long long int)(va_arg(ap, long long int)), ret);
		else if (*str == 'u')
			ft_putnbr_unsigned((long long int)(va_arg(ap, long long int)), ret);
		else if (*str == 'x' || *str == 'X')
			ft_putnbr_hexa((long long int)(va_arg(ap, long long int)), *str, ret);
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
		*i += 1;
	}
}

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

int			ft_conv(const char *str, va_list ap, int *ret)
{
	int		i;

	i = 0;
	if (*str == 'h')
		ft_h(str, ap, &i, &ret);
	else if (*str == 'l')
		ft_l(str, ap, &i, &ret);
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
	else if (*str == '%')
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

//int main()
//{
//	int b = -15248;
//	double z = 2147.2154;
//	char c = 'c';
//	char *s = "salut";
//	int ret ; 
//	int ret2;
//	ret = printf(" salut %x %c %p %s %f\n", b, c, s, s, z);
//	ret2 = ft_printf(" salut %x %c %p %s %f\n", b, c, s, s, z);
//	printf("%0-15d\n", ret);
//	ft_printf("%d", ret2);
//	//ft_printf("%s\n", 0);
//	printf("%.2s\n", 0);
//}
