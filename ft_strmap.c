#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	size_t i;

	i = 0;
	if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
