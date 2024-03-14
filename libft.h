/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:32:15 by angemart          #+#    #+#             */
/*   Updated: 2024/03/14 13:32:20 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // quitarla, solo para hacer pruebas con main

int					ft_atoi(const char *str);
char				*ft_strdup(const char *str);
int					ft_strlen(const char *str);

#endif
