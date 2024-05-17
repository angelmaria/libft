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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char *) malloc(sizeof(char) * ft_strlen(src) + 1))) // Error norminette for "assignment in control structure"
		return (NULL);
	while (*src)
		new[i++] = *src++;
	new[i] = '\0';
	return (new);
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
