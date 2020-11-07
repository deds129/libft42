
#include "libft.h"
/*
 *  Функция  записывает  length  байтов из буфера buffer в
      файл, определенный дескриптором файла fd. Эта операция
      чисто  'двоичная' и без  буферизации.  Реализуется как
      непосредственный вызов DOS.
 */
void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main(void)
{
	ft_putchar_fd('a',-1);
}
