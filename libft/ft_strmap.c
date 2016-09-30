/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:03:08 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 16:03:11 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *string, char (*func)(char))
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * ft_strlen(string));
	i = 0;
	while (string[i])
	{
		new[i] = func(string[i]);
		i++;
	}
	return (new);
}
