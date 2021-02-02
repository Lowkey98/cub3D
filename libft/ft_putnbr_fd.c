/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_putnbr_fd.c									 :+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/15 10:50:12 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/10/18 12:14:08 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long b;

	b = n;
	if (b < 0)
	{
		ft_putchar_fd('-', fd);
		b = b * -1;
	}
	if (b > 9)
	{
		ft_putnbr_fd(b / 10, fd);
		ft_putnbr_fd(b % 10, fd);
	}
	else
		ft_putchar_fd(b + '0', fd);
}
