
#include "libft.h"
/*
 * Выделяет (с помощью malloc) и возвращает подстроку из строки,
 * указанной в аргументе.
 * Подстрока начинается с индекса 'start' и имеет максимальный размер 'len'.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	size_t				i;
	size_t				j;

	substr = NULL;
	i = 0;
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			substr[j] = s[i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

int main(void)
{
	char str1 [30] = "01234567890123456789";
	printf("%s\n", ft_substr(str1, 2, 10));
	return (NULL);
}
