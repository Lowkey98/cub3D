/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_memcpy.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/17 12:20:18 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/11/03 20:06:16 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char		*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	s = (unsigned char*)str2;
	d = (unsigned char*)str1;
	if (d == s)
		return (d);
	if ((!s && !d))
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
