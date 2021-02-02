/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_memccpy.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/17 12:09:34 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/11/03 16:00:51 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char*)s2;
	d = (unsigned char*)s1;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
