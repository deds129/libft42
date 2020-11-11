#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *newstr;
	size_t len;
	size_t i;

	if(!s || !f)
		return (NULL);
	len = ft_strlen(s);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while(s[i])
	{
		newstr[i] = f(i,s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}