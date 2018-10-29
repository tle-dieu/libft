#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	if (s)
	{
		i = 0;
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (!s[i])
			return (ft_strdup(""));
		while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
			j--;;
		return (ft_strsub(s, i, (j - i + 1)));
	}
	return (NULL);
}
