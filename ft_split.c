/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:48:07 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:10 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_cnt(char const *s, char c) 
{
	size_t		cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s != '\0' && *s != c) 
				s++;
		}
	}
	return (cnt);
}

char	**free_machine(char **s, size_t idx) 
{
	while (s[idx] != NULL && idx >= 0)
	{
		free(s[idx]); 
		s[idx] = NULL;

		idx--; 
	}
	free(s); 
	s = NULL; 
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		idx;
	size_t		len;
	size_t		word_cnt;
	char		**words; 

	words = NULL; 
	if (!s || !(words = (char **)malloc(sizeof(char *) * (get_cnt(s, c) + 1)))) 
		return (NULL);
	word_cnt = get_cnt(s, c);
	idx = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (*(s + len) && *(s + len) != c)
				len++;
			if (idx < word_cnt && !(words[idx++] = ft_substr(s, 0, len)))
				return (free_machine(words, idx));
			s += len;
		}
	}
	words[idx] = 0;
	return (words);
}
// Test (borrar)
int main(void)
{
    char *frase = "Explorando el mundo de la programación en C";
    char delimitador = ' '; // Suponiendo que queremos dividir la frase por espacios
    char **palabras;

    palabras = ft_split(frase, delimitador);
    if (!palabras)
    {
        printf("Error: No se pudo dividir la frase.\n");
        return (1);
    }

    for (size_t i = 0; palabras[i] != NULL; i++)
    {
        printf("Palabra %zu: '%s'\n", i, palabras[i]);
        free(palabras[i]); // Liberamos cada palabra individualmente
    }
    free(palabras); // Liberamos el arreglo de palabras

    return (0);
}