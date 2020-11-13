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

//Кол-во слов в строке
size_t ft_wcounter(char const *s, char c)
{
	size_t i;
	size_t counter;
	size_t len;
	int flag;

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

size_t ft_wlen(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}


/*
char **ft_split(char const *s, char c)
{
}
*/

int main(void)
{
	char *str = " Hello1wor1111d1ld";
	printf("%ld\n",ft_wcounter(str,'1'));
	printf("%ld\n",ft_wlen(str,'1'));
}