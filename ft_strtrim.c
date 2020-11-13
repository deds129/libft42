#include "libft.h"

/*

 strnstr + substr
 пишем две функции 1)

 set: 12
 s: 112|345|22221
 result: 345

 1)найти индекс первого несовпадения
 2)найти индекс второго несовпадения
 3)вычесть длину - 1 несовп 2 несовп
 3) субстр
 */
int indexator(char const *s1, char const *set)
{
	size_t i;
	size_t j;
	size_t flag;

	i = 0;
	while (s1[i])
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				j++;
				break;

			} else
			{
				flag++;
				j++;
			}
		}
		if (flag >= ft_strlen(set))
		{
			return i;
		}
		i++;
	}
	return (-1); //?
}


/*
* Выделяет (с помощью malloc (3)) и возвращает копию
’S1’ с удаленными символами, указанными в ’set’
от начала и до конца строки.
 */
int revindexator(char const *s1, char const *set)
{
	size_t i;
	size_t j;
	size_t flag;

	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				j++;
				break;

			} else
			{
				flag++;
				j++;
			}
		}
		if (flag >= ft_strlen(set))
		{
			return i;
		}
		i--;
	}
	return (-1); //?
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char*trimstr;
	size_t start;
 	size_t len;
 	size_t temp;

 	if(!s1 || !set)
		return (NULL);

	start = indexator(s1,set);
	temp = revindexator(s1,set);
	len = temp - start + 1;

	trimstr = (char *)malloc(sizeof(char *) * len + 1);

	trimstr = ft_substr(s1, start, len);
	return (trimstr);
}
/*
int main(void)
{
	char *a = "12345167112";
	const char *set = "123";
	printf("%d\n",indexator(a,set));
	printf("%d\n",revindexator(a,set));
	char *b = ft_strtrim(a,set);
	printf("%s\n",b);
	return (0);
}
 */


