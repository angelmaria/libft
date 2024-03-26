/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cash <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:26:01 by cash              #+#    #+#             */
/*   Updated: 2024/03/26 10:15:08 by cash             ###   ########.fr       */
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
// Same with less code
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