/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:03:05 by tmack             #+#    #+#             */
/*   Updated: 2016/08/08 08:06:08 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_absl(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

long int	ft_len(long int nbr)
{
	long int	len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int nbr)
{
	char		*c;
	long int	len;
	int			sign;

	len = ft_len(nbr);
	sign = (nbr < 0) ? -1 : 1;
	c = (char *)malloc(sizeof(char) * (len + 1));
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_absl(nbr % 10);
		nbr = ft_absl(nbr / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
