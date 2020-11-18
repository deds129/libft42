
#include "libft.h"

size_t ft_wcounter(char const *s, char c)
{
	size_t i;
	size_t counter;
	size_t len;

	if(!s)
		return (0);
	counter = 0;
	i = 0;
	len = ft_strlen(s);
	if(s[0] != c)
		counter++;
	while(i < len - 1)
	{
		if(s[i] == c && s[i+1] != c)
			counter++;
		i++;
	}
	return (counter);
}


/* метод для нахождения длинны слова */
size_t ft_wlen(char const *s, char c, int i)
{
	size_t idx;

	idx = 0;
	if(!s)
		return (0);
	while (s[i] && s[i] != c)
	{
		i++;
		idx++;
	}
	return (idx);
}

char *ft_arrfill(char const *s, size_t len, size_t j)
{
	size_t  i;
	char    *str;
	if(!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[j];
		j++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

char **ft_arr_free(char **split)
{
	while (*split)
		free(*split++);
	free(split);
	return (NULL);
}


char **ft_split(char const *s, char c)
{
	/*возвращаемый двумерный массив*/
	char				**split;
	/*кол-во слов в двумерном массиве [i][]*/
	size_t				words_count;

	/*счетчик для исх строки*/
	size_t				i;
	/*счетчик для слов (элементов строки)*/
	size_t				j;
/*кол-во cимволов в строке  [][j]*/
	size_t				temp;

	i = 0;
	j = 0;

	temp = 0;

	//выделяем память под строки
	if(!s)
		return (NULL);
	words_count = ft_wcounter((char *)s,c);
	split = (char **)malloc(sizeof(char *) * (words_count + 1));
	if(!split)
		return (NULL);
	while (j < words_count  && s[i] != '\0')
	{
		if(s[i] != c)
		{
			temp = ft_wlen((char *)s,c,i);
			if(!(split[j++] = ft_arrfill((char *)s,temp,i)))
				ft_arr_free(split);
			i +=temp;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}


int main(void)
{
	char *str1 = "";
	//printf("%ld\n",ft_wcounter(str1,'|'));
	//printf("%ld\n",ft_wlen(str1,'|',2));
	printf("%s\n", ft_split(str1,'|')[0]);
	printf("%s\n", ft_split(str1,'|')[0]);
}
/*
 * ft_split:      [OK] [OK] [OK] [OK] [OK] [OK] [CRASH] [OK] [OK] {protected}
[crash]: your split does not work with empty string
Test code:
	char *s = "";
	char **result = ft_split(s, '\65');
	split_cmp_array(expected, result);
 */