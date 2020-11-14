/*
 *#1. The string to be split.
 *#2. The delimiter character.
 *
 * The array of new strings resulting from the split.
   NULL if the allocation fails.

   	Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must be
ended by a NULL pointer.

 Выделяет (с помощью malloc (3)) и возвращает массив
строк, полученных разделением 's' с помощью
символ ’c’ в качестве разделителя. Массив должен быть
заканчивается указателем NULL.

 1)найти символ в строке
 2)определить сколько массивов необходимо создать
 3)определить длину слова (элемента будущего массива)
 3)выделить память под каждый массив
 4)выделить память под все массивы
*/


#include "libft.h"

char			**ft_arr_free(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}


/*
 * подсчет кол-ва слов в строке
 */
size_t ft_wcounter(char const *s, char c)
{
	size_t i;
	size_t counter;
	size_t len;

	if(!s || !c)
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
size_t ft_wlen(char const *s, char c, int begin_idx)
{
	size_t i;
	char temp;

	i  = begin_idx;
	temp = s[i];
	while (temp && temp != c)
	{
		temp = s[++i];
	}
	return (i);
}

char **ft_split(char const *s, char c)
{
	/*возвращаемый двумерный массив*/
	char				**split;
	/*кол-во слов в двумерном массиве [i][]*/
	size_t				words_count;
	/*кол-во cимволов в строке массиве [][j]*/
	size_t				str_len;
	/*счетчик для посдечета*/
	size_t				i;
	size_t				j;


	//выделяем память под строки
	if(!s)
		return (NULL);
	words_count = ft_wcounter(s,c);
	split = (char **)malloc(sizeof(char *) * (words_count + 1));
	if(!split)
		return (NULL);

	i = 0;
	str_len = 0;
	while (i < words_count)
	{
		j = 0;
		split[i] = (char *)malloc(sizeof(char) * ft_wlen(s,c,str_len) -
				(str_len + 1));
		if(split[i] == NULL)
			return (NULL);
		while (j < (ft_wlen(s,c,str_len)) - str_len)
		{
			split[i][j] = s[str_len + j];
			j++;
		}
		split[i][j] = '\0';
		str_len = ft_wlen(s,c,str_len) + 1;
		i++;
	}
	split[i] = NULL;
	return (split);
}

/*
int main(void)
{
	char *str = "Hello1wor1111d1ld";
	printf("%ld\n",ft_wcounter(str,'1'));
	printf("%ld\n",ft_wlen(str,'1',0));
}
 */

