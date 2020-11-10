#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *newstr;
	size_t len;
	ssize_t i;

	i = 0;
	len = ft_strlen(s);
	newstr = (char *)malloc(sizeof(char *) * (len + 1));
	if (newstr == NULL || s == NULL)
		return (NULL);
	while(s[i])
	{
		newstr[i] = f(i,s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

