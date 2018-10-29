#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t words;

	words = 0;
	while (*s)
	{
		if (*s != c)
			words++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	words;
	char	**tab;

	if (s)
	{
		words = ft_count_words(s, c);
		if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
			return (NULL);
		i = 0;
		j = 0;
		while (j < words)
		{
			len = 0;
			while (s[i] == c && s[i])
				i++;
			while (s[i] != c && s[i])
			{
				i++;
				len++;
			}
			tab[j++] = ft_strsub(s, i - len, len);
		}
		tab[j] = NULL;
		return (tab);
	}
	return (NULL);
}
