/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:33:19 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 15:33:22 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** not tested
*/

int				ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || (c <= '\r' && c >= '\n'));
}
