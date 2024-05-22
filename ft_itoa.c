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

static size_t	ft_intlen(long nb)
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
	char	*strnum;
	size_t	len;
	long	nb;

	if (n == '-2147483648')
		return (ft_strdup("-2147483648"));
	nb = n;
	len = ft_intlen(nb);
	strnum = (char *)malloc(sizeof(char) * len + 1);
	if (!strnum)
		return (NULL);
	strnum[len--] = '\0';
	if (n == 0)
		strnum[0] = '0';
	if (nb < 0)
	{
		strnum[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		strnum[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (strnum);
}
