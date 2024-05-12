/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:48:28 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:34 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/* 
int main(int argc, char **argv)
{
	for(int i = 0; i < argc; i++)
		printf("Len [%d](\'%s\') = %ld\n", i, argv[i], ft_strlen(argv[i]));
	return (0);
} */
