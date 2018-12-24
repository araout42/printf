/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 23:25:25 by araout            #+#    #+#             */
/*   Updated: 2018/12/23 23:25:54 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_i(char const *s, int **ret)
{
	int	i;

	i = 0;
	while (s[i])
	{
		**ret += 1;
		ft_putchar(s[i]);
		i++;
	}
}
