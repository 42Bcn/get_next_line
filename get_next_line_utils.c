#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)(c))
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)(c))
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*des;

	des = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!des)
		return (NULL);
	i = 0;
	while (s[i])
	{
		des[i] = s[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

