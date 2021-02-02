/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_calloc.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/13 14:50:56 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/10/23 16:53:57 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	int		i;

	i = 0;
	if (!(ptr = malloc(nitems * size)))
		return (0);
	while ((int)(nitems * size) > i)
	{
		*(char*)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
