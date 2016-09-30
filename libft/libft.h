/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:42:22 by tmack             #+#    #+#             */
/*   Updated: 2016/07/31 11:55:33 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

void			tmack_header(void);
/*
** mem
*/
void			ft_free_2(char **c);
int				ft_memcmp(const void *original, const void *new, size_t len);
void			*ft_memcpy(void *dest, const void *source, size_t len);
void			*ft_memccpy(void *dest, const void *source, int c, size_t len);
void			*ft_memmove(void *dest, const void *source, size_t len);
void			*ft_memset(void *destinatino, int int_value, size_t len);
void			*ft_memchr(const void *haystack, int needle, size_t len);
void			ft_bzero(void *string, size_t len);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			ft_memdel(void **pointer);
void			ft_strdel(char **pointer);
/*
** char
*/
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
/*
** string
*/
char    		*ft_strndup(const char *s, size_t n);
int				ft_get_next_line(int const fd, char **line);
size_t			ft_strlen(const char *source);
size_t			ft_strnlen(const char *source, size_t max);
char			*ft_strchr(const char *haystack, int needle);
char			*ft_strrchr(const char *haystack, int needle);
int				ft_strcmp(const char *first, const char *second);
int				ft_strequ(const char *first, const char *second);
int				ft_strncmp(const char *first, const char *second, size_t max);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle
							, size_t len);
char			*ft_strcpy(char *dest, const char *source);
char			*ft_strncpy(char *dest, const char *source, size_t max);
char			*ft_strdup(const char *source);
char			*ft_strcat(char *first, const char *second);
char			*ft_strncat(char *first, const char *second, size_t len);
size_t			ft_strlcat(char *first, const char *second, size_t size);
void			ft_strclr(char *string);
void			ft_striter(char *string, void (*func)(char *));
void			ft_striteri(char *string, void (*func)(unsigned int, char *));
char			*ft_strmap(const char *string, char (*func)(char));
char			*ft_strmapi(const char *string
							, char (*func)(unsigned int, char));
int				ft_strequ(char const *first, char const *second);
int				ft_strnequ(char const *first, char const *second, size_t len);
char			*ft_strsub(char const *string, size_t start, size_t len);
char			*ft_strjoin(char const *first, char const *second);
char			*ft_strtrim(char const *string);
char			**ft_strsplit(char const *string, char c);
/*
** printing
*/
void			ft_putchar(char c);
void			ft_putstr(char const *source);
void			ft_putnbr(int number);
void			ft_putendl(char const *source);
char			*ft_itoa(int number);
int				ft_atoi(const char *str);
void			ft_putchar_fd(char c, int file_descriptor);
void			ft_putstr_fd(char const *source, int file_descriptor);
void			ft_putnbr_fd(int number, int file_descriptor);
void			ft_putendl_fd(char const *source, int file_descriptor);

int				ft_abs(int number);

#endif
