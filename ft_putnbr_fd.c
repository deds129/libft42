
#include "libft.h"

/*Outputs the integer ’n’ to the given file
descriptor.*/
void ft_putnbr_fd(int n, int fd)
{
	unsigned int	n1;

	n1 = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = n * -1;
	}
	else
		n1 = (unsigned  int)n;
	if (n1 >= 10)
		ft_putnbr_fd(n1 / 10, fd);
	ft_putchar_fd(n1 % 10 + '0', fd);
}