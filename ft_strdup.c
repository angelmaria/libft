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

// BORRAR ESTE CONTENIDO ANTES DE SUBIRLO
int	main(int ac, char **av)
{
	char	*mine;
	char	*theirs;

	if (ac == 2)
	{
		mine = ft_strdup(av[1]);
		theirs = strdup(av[1]);
		printf(":%s:\n:%s:\n", mine, theirs);
	}
	return (0);
}
