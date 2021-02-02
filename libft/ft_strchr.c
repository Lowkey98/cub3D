/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_strchr.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <ayafdel@student.42.fr>			+#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/12 13:16:32 by ayafdel			#+#	#+#			 */
/*	Updated: 2020/12/09 09:54:22 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, char x)
{
	while (*str)
	{
		if (*str == x)
			return ((char*)str);
		str++;
	}
	if (!x)
		return ((char*)str);
	return (0);
}
