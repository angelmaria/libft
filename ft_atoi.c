/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:08:48 by angemart          #+#    #+#             */
/*   Updated: 2024/03/13 13:33:29 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 1. Obviar espacios en blanco
 2. Transformar el signo negativo si lo hubiera
 3. La conversión de ascii a integer
 */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

// BORRAR CUANDO SE SUBA A LA VLOGOSPHERE
// int	main(int ac, char **av)
// {
// 	int test1; 
// 	int test2;

// 	if (ac == 2)
// 	{
// 		test1 = ft_atoi(av[0]);
// 		test2 = ft_atoi(av[1]);
// 		printf("mine: %d | theirs: %d\n", test1, test2);
// 	}
// 	return (0);
// }
