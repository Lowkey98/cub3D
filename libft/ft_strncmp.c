/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_strncmp.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/07/16 12:57:36 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/11/03 16:03:22 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		if (i + 1 == n)
			break ;
		i++;
	}
	return (((unsigned char)(s1)[i]) - ((unsigned char)(s2)[i]));
}
