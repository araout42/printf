/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:13:11 by araout            #+#    #+#             */
/*   Updated: 2018/12/29 14:15:56 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_power(uintmax_t nb, int power)
{
	uintmax_t result;

	result = nb;
	power--;
	while (power--)
		result *= nb;
	return (result);
}
