/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:02:33 by alamorth          #+#    #+#             */
/*   Updated: 2018/12/03 13:19:27 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_bits(int nbr, int index)
{
	return ((nbr >> index) & 1);
}
