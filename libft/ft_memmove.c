/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:50:08 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 15:52:43 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *source, size_t len)
{
	char	copy[len];

	ft_memcpy(copy, source, len);
	ft_memcpy(dest, copy, len);
	return (dest);
}
