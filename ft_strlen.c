/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cash <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:11:34 by cash              #+#    #+#             */
/*   Updated: 2024/03/29 12:11:39 by cash             ###   ########.fr       */
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
