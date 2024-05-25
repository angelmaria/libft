/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:44:27 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:44:32 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(long nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
	{
		count++;
		return (count);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	long	pos;

	len = ft_num_len(n);
	pos = n;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	if (pos < 0)
	{
		res[0] = '-';
		pos = -(long)pos;
	}
	if (pos == 0)
		res[0] = '0';
	res[len--] = '\0';
	while (pos)
	{
		res[len] = ((pos % 10) + '0');
		pos /= 10;
		len--;
	}
	return (res);
}
