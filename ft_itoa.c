
#include "libft.h"
/*
 * Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.

 Выделяет (с помощью malloc (3)) и возвращает строку
представляющий целое число, полученное в качестве аргумента.
Отрицательные числа необходимо обрабатывать.

 1)найти длину числа
 2) выделить память
 3) поциферно записать число в строку
 4)обработать отрицательные числа
 */
size_t num_len(int n)
{
	size_t len;
	long long int n1;

	n1 = n;


	len = 0;
	if(n == 0)
		return (1);
	if (n < 0)
	{
		n1 *= -1;
		len++;
	}
	while (n1 > 0)
	{
		n1 = n1/10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n1)
{
	char *str;
	size_t len;
	long long int n;

	n = (long long int)n1;
	len = num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if(!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	if(n < 0)
	{
		*str = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len--] = (n%10) + '0';
		n /= 10;
	}
	return  (str);
}
/*
int main(void)
{
	printf("%ld\n",num_len(-5859));
	printf("%s\n",ft_itoa(-1));
	return (0);
}
*/

