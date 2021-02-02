/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_memcmp.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/17 12:06:58 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/11/03 18:46:33 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	if (!n)
		return (0);
	while (--n)
	{
		if (*(char*)str1 != *(char *)str2)
			break ;
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
