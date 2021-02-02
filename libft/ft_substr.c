/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_substr.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/13 15:35:14 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/10/23 18:48:18 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	int		i;
	char	*str1;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strlen(str) < start + 1)
	{
		str1 = malloc(1);
		str1[0] = 0;
		return (str1);
	}
	str1 = malloc(len + 1);
	if (str1 == NULL)
		return (NULL);
	while (len--)
	{
		str1[i] = str[start + i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
