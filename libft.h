/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:32:15 by angemart          #+#    #+#             */
/*   Updated: 2024/03/19 00:34:59 by cash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // quitarla, solo para hacer pruebas con main

int					ft_atoi(const char *str);
void                ft_bzero(void *s, size_t n);
int                 ft_isalnum(int c);
int                 ft_isalpha(int c);
int                 ft_isascii(int c);
int                 ft_isdigit(int c);
int                 ft_isprint(int c);
char                *ft_itoa(int c);
void                *ft_memchr(const void *s, int c, size_t n);
int                 ft_memcmp(const void *s1, const void *s2, size_t n);
void                *ft_memcpy(void *dest, const void *src, size_t n);
void                *ft_memmove(void *dst, const void *src, size_t len);
void                *ft_memset(void *b, int c, size_t len);
void                ft_puchar_fd(char c, int fd);
void                ft_putendl_fd(char *s, int fd);
void                ft_putnbr_fd(int n);
void                ft_putstr_fd(char *s, int fd);
char                **ft_split(char const *s, char c);
char				*ft_strdup(const char *str);
int					ft_strlen(const char *str);
char                *ft_substr(char const *s, unsigned int start, size_t len);

#endif
