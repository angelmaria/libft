/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:48:44 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:49 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
// int main(int argc, char **argv)
// {
// 	(void) argc;
// 	int start = atoi(argv[2]);
// 	int len = atoi(argv[3]);
// 	char *res = ft_substr(argv[1], start, len);

// 	printf("Sending argv[1] = \'%s\'\n", argv[1]);
// 	printf("Sending argv[2] = %d\n", start);
// 	printf("Sending argv[3] = %d\n", len);

// 	printf("Returning \'%s\'\n", res);
// }
//
//
// int main() {
//     const char *source_string = "Hello, world!";
//     unsigned int start_index = 7; // Start at index 7 (after the comma)
//     size_t length = 5; // Extract 5 characters

//     char *sub_string = ft_substr(source_string, start_index, length);

//     if (sub_string == NULL) {
//         printf("Error: ft_substr failed to allocate memory.\n");
//     } else {
//         printf("Substring: %s\n", sub_string);
//         free(sub_string); // Remember to free the allocated memory
//     }

//     return 0;
// }
