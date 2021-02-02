/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_memmove.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/17 12:08:09 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/10/29 12:55:05 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int i;

	i = 0;
	if (!str2 && !str1)
		return (0);
	if (str2 > str1)
	{
		while (n--)
		{
			((char*)str1)[i] = ((char*)str2)[i];
			i++;
		}
	}
	if (str1 > str2)
		while (n--)
			((char*)str1)[n] = ((char*)str2)[n];
	return (str1);
}
