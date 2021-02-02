/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_strdup.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <ayafdel@student.42.fr>			+#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/13 15:02:03 by ayafdel			#+#	#+#			 */
/*	Updated: 2020/12/11 17:56:15 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char *dst;

	dst = malloc(ft_strlen(s) + 1);
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, (char *)s);
	return (dst);
}
