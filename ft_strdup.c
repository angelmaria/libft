/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:37:19 by angemart          #+#    #+#             */
/*   Updated: 2024/03/18 12:27:50 by cash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// Test (borrar)
int main(void)
{
    const char *original = "Texto de prueba";
    char *duplicado;

    duplicado = ft_strdup(original);
    if (duplicado == NULL)
    {
        printf("Error al duplicar la cadena.\n");
        return 1;
    }

    printf("Original: %s\n", original);
    printf("Duplicado: %s\n", duplicado);
    printf("Longitud del original: %zu\n", ft_strlen(original));
    printf("Longitud del duplicado: %zu\n", ft_strlen(duplicado));

    // No olvides liberar la memoria asignada con malloc
    free(duplicado);

    return 0;
}
