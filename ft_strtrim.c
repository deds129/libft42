#include "libft.h"

/*
 * Выделяет (с помощью malloc (3)) и возвращает копию
’S1’ с удаленными символами, указанными в ’set’
от начала и до конца строки.

 strnstr + substr
 пишем две функции 1)

 set: 12
 112|345|22221

 1)найти индекс первого несовпадения
 2)найти индекс второго несовпадения
 3)вычесть длину - 1 несовп 2 несовп
 3) субстр
 */

int indexator(const char *str, const char *dict)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (dict[j] != '\0' && str[i] != '\0')
		{
			if(str[i] != dict[j])
				return (i); //выкидывается первое несовпадение
				j++;
		}
		i++;
	}
	return (0);
}

char	*linereverser(char *str)
{
	size_t len;
	size_t i;
	char *newstr;

	len = ft_strlen(s1);

	while (len--)
	{
		//write code here
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tstr;
	size_t	for_start;
	//size_t	for_len;
	size_t	len;


	tstr = (char *)malloc(sizeof(s1) * ft_strlen(s1));
	// проверяем на NULL
	if (tstr == NULL || set == NULL)
		return (NULL);

	//char	*ft_substr(char const *s1, unsigned int start, size_t len)
	for_start = indexator(s1,set);

	len = ft_strlen(s1);
	printf("%zu\n",len);

	return (char *)s1;
}

int main(void)
{
	char a[20] = "11111234522212";
	const char set[10] = "12";
	char *b;
	b = ft_strtrim(a,set);
	return (0);
}

