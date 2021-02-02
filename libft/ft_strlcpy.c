/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_strlcpy.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/11 18:10:24 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/11/15 08:19:31 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char*)src);
	if (n == 0)
		return (len);
	while (i < n - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
