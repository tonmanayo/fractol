/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:02:01 by tmack             #+#    #+#             */
/*   Updated: 2016/06/17 14:31:42 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *first, const char *second, size_t size)
{
	size_t		end;
	size_t		i;

	if (size == 0)
		return (ft_strlen(second));
	end = ft_strlen(first);
	if (end > size - 1)
		return (size + ft_strlen(second));
	i = 0;
	while (second[i] && end + i < size - 1)
	{
		first[i + end] = second[i];
		i++;
	}
	first[i + end] = '\0';
	return (end + ft_strlen(second));
}
