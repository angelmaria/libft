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
	if (!s || !(words = (char **)malloc(sizeof(char *) * (get_cnt(s, c) + 1)))) // Hago esto porque me daba error de "Assignment in control structure" por realizar una asignación dentro de una estructura de control (if, while..). Se debe realizar la asignación fuera del if.
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
// Esta función supera las 25 líneas. Habría que dividirla en funciones más pequeñas como:
// static char	**allocate_words(char const *s, char c, size_t *word_cnt)
// {
// 	char **words;

// 	*word_cnt = get_cnt(s, c);
// 	words = (char **)malloc(sizeof(char *) * (*word_cnt + 1));
// 	return (words);
// }

// static char	*get_next_word(char const **s, char c, size_t *len)
// {
// 	*len = 0;
// 	while (**s && **s == c)
// 		(*s)++;
// 	while (*(*s + *len) && *(*s + *len) != c)
// 		(*len)++;
// 	return (ft_substr(*s, 0, *len));
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	idx;
// 	size_t	len;
// 	size_t	word_cnt;
// 	char	**words;

// 	if (!s)
// 		return (NULL);
// 	words = allocate_words(s, c, &word_cnt);
// 	if (!words)
// 		return (NULL);
// 	idx = 0;
// 	while (idx < word_cnt)
// 	{
// 		words[idx] = get_next_word(&s, c, &len);
// 		if (!words[idx])
// 			return (free_machine(words, idx));
// 		s += len;
// 		idx++;
// 	}
// 	words[idx] = NULL;
// 	return (words);
// }
// Testing ----------------------------------------------------------------
/* 
int main(int argc, char **argv)
{	
	(void)argc;
	char **words;
	
	words = ft_split(argv[1], argv[2][0]);

	int i = 0;
	for(; words[i]; i++)
		printf("words[%d] = \'%s\'\n", i, words[i]);
	printf("words[%d] = NULL\n", i);

	ft_delete_matrix(words);
}
 */
