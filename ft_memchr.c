/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:44:43 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:44:47 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i); // same as return (&str[i]); (borrar antes de mandar, no pasa la norminette)
		i++;
	}
	return (NULL);
}
// Key Points:

// memchr is efficient for finding the first occurrence of a character within a memory block.
// It's important to consider the size of the memory block (n) to avoid exceeding valid memory boundaries.
// The return value is a pointer, so you might need to cast it back to the appropriate data type for further processing (e.g., cast to char* for string manipulation).
// Remember that memchr only searches for the first occurrence. If you need to find all occurrences, you'll need to implement a loop or use a different function like strchr (for null-terminated strings).
