/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:46:21 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:46:29 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *target, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (target == NULL || target[0] == '\0')
		return ((char *)src);
	while (src[i] != '\0' && i < n)
	{
		if (src[i] == target[j])
		{
			while (src[i + j] == target[j] && i + j < n)
			{
				if (target[j + 1] == '\0')
					return ((char *)src + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
