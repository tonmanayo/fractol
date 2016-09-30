/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 08:42:33 by tmack             #+#    #+#             */
/*   Updated: 2016/07/31 10:48:49 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

char	*buffer(int const fd, char *string, int *rd_byte)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE);
	*rd_byte = read(fd, tmp, BUFF_SIZE);
	tmp[*rd_byte] = '\0';
	string = ft_strjoin(string, tmp);
	free(tmp);
	return (string);
}

int		ft_get_next_line(int const fd, char **line)
{
	static char		*buf = "";
	int				ret;
	char			*str;

	if (line < 0 || fd < 0)
		return (-1);
	ret = 1;
	if (buf[0] == '\0')
		buf = ft_strnew(0);
	while (ret > 0)
	{
		if ((str = ft_strchr(buf, '\n')) != 0)
		{
			*str = '\0';
			*line = ft_strdup(buf);
			ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		else
			*line = ft_strdup(buf);
		buf = buffer(fd, buf, &ret);
	}
	free(str);
	return (ret);
}
