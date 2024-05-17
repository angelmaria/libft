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
// Test (borrar)
// int main(void)
// {
//     char *str1 = "Hola, mundo!";
//     char *str2 = "";

//     printf("La longitud de '%s' es: %zu\n", str1, ft_strlen(str1));
//     printf("La longitud de una cadena vacía es: %zu\n", ft_strlen(str2));

//     return 0;
// }
