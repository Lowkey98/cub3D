#include "libft.h"
void	ft_putnbr(int n)
{
	long b;

	b = n;
	if (b < 0)
	{
		ft_putchar('-');
		b = b * -1;
	}
	if (b > 9)
	{
		ft_putnbr(b / 10);
		ft_putnbr(b % 10);
	}
	else
		ft_putchar(b + '0');
}
