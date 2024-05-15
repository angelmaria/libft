/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:45:46 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:45:55 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len -1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
// Same with less code. Ask if you can use other functions in here (like in ft_putnbr_fd where we use ft_putstr_fd and ft_putchar_fd).
// void		*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	char	*tmp;

// 	tmp = (char *)malloc(sizeof(char) * len);
// 	if (tmp == NULL)
// 		return (NULL);
// 	ft_memcpy(tmp, src, len);
// 	ft_memcpy(dst, tmp, len);
// 	free(tmp);
// 	return (dst);
// }

// ----------------------------------------------------------------

// Otra alternativa más legible ya que permite utilizar la notación de índice de array [i] en lugar de la artimética de punteros 
// y la desreferenciación explícita
// #include "libft.h"

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	int	i;

// 	if (!dst || !src)
// 		return (NULL);

// 	// alternativa más legible
// 	char *dest;
// 	char *sourc;
// 	dest = (char *)dst;
// 	sourc = (char *)src;

// 	if (dest > sourc)
// 	{
// 		i = (int)len -1;
// 		while (i >= 0)
// 		{
// 			dest[i] = sourc[i];
// 			i--;
// 		}
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < (int)len)
// 		{
// 			dest[i] = sourc[i];
// 			i++;
// 		}
// 	}
// 	return (dest);
// }