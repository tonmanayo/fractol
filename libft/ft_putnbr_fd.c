/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:56:13 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 15:56:16 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int number, int file_descriptor)
{
	char	*string;

	string = ft_itoa(number);
	ft_putstr_fd(string, file_descriptor);
	free(string);
}
