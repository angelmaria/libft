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

size_t	word_count(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (count);
}

char	**free_array(char **s, size_t idx)
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

size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) && *(s + len) != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t		idx;
	size_t		len;
	size_t		word_cnt;
	char		**words;

	words = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !words)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = get_word_len(s, c);
			words[idx++] = ft_substr(s, 0, len);
			if (!words[idx])
				return (free_array(words, idx));
			idx++;
			s += len;
		}
	}
	words[idx] = 0;
	return (words);
}
