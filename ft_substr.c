
#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (substr == NULL)
		return (NULL);
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if(i <= start &&  j < len)
		{
			substr[j] = s[i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}


