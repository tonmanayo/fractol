/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:06:41 by tmack             #+#    #+#             */
/*   Updated: 2016/07/28 15:46:47 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int		ft_count_parts(const char *str, char c)
{
	int		count;
	int		in_substring;

	in_substring = 0;
	count = 0;
	while (*str != '\0')
	{
		if (in_substring == 1 && *str == c)
			in_substring = 0;
		if (in_substring == 0 && *str != c)
		{
			in_substring = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static int		ft_word_len(const char *str, char c)
{
	int		len;

	len = 0;
	while (*str != c && *str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**t;
	int		nbr_words;
	int		i;

	i = 0;
	nbr_words = ft_count_parts((const char *)str, c);
	t = (char **)malloc(sizeof(*t) * (ft_count_parts((const char *)str, c) + 1));
	if (t == NULL)
		return (NULL);
	while (nbr_words--)
	{
		while (*str == c && *str != '\0')
			str++;
		t[i] = ft_strsub((const char *)str, 0, ft_word_len((const char *)str, c));
		if (t[i] == NULL)
			return (NULL);
		str = str + ft_word_len(str, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
