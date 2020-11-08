
#include "libft.h"

/*Outputs the integer ’n’ to the given file
descriptor.*/
void ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-',fd);
	if (n == 0)
		ft_putchar_fd('0',fd);

}

