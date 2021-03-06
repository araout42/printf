/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 05:04:09 by araout            #+#    #+#             */
/*   Updated: 2019/04/14 14:54:22 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					checkerror(char **line, int fd, char **buf)
{
	if (!line || fd < 0)
		return (0);
	if (!(*buf = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (0);
	return (1);
}

int					readnl(int fd, char **str, char **buf, int i)
{
	int				res;
	char			*tmp;

	while ((res = read(fd, *buf, BUFF_SIZE)) > 0 && ++i != -55)
	{
		tmp = *buf;
		tmp[res] = '\0';
		tmp = *str;
		if (*str)
			*str = ft_strjoin(*str, *buf);
		else
			*str = ft_strdup(*buf);
		if (i > 0)
			ft_memdel((void *)&tmp);
		if (ft_strchr(*str, '\n'))
		{
			ft_memdel((void *)buf);
			return (res);
		}
	}
	ft_memdel((void *)buf);
	return (res);
}

char				*ft_realoc_str(char **str, int size, int i)
{
	char	*ret;

	if (!(ret = ft_memalloc(sizeof(*ret) * size)))
		return (NULL);
	while (str[++i])
		ret = str[i];
	ft_strdel(str);
	return (ret);
}

int					fillline(char **line, char **str, int *res)
{
	int				i;
	char			*tmp;

	tmp = *str;
	i = 0;
	while (tmp && tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (i == 0 || tmp[0] == '\0')
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	else if (!(*line = ft_strsub(tmp, 0, i)))
		return (-1);
	if (!ft_strlen(*str) && *res == 0)
		return (0);
	if (i >= (int)ft_strlen(*str))
		ft_strdel(str);
	else
		*str = ft_realoc_str(str, ft_strlen(*str) - (i + 1), i);
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*str[4096] = {NULL};
	int				res;
	char			*buf;
	int				i;
	int				ret;

	i = -1;
	if (!checkerror(line, fd, &buf))
		return (-1);
	if ((res = readnl(fd, &str[fd], &buf, i)) == -1)
		return (-1);
	ret = fillline(line, &str[fd], &res);
	if (ret == 1)
		ft_strdel(str);
	return (ret);
}
