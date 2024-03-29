#include "libft.h"

size_t		get_cnt(char const *s, char c)
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

char		**free_machine(char **s, size_t idx)
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

char		**ft_split(char const *s, char c)
{
	size_t		idx;
	size_t		len;
	size_t		word_cnt;
	char		**words;

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