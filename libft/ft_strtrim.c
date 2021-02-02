/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_strtrim.c										:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/13 21:39:47 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/10/29 13:19:04 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int			firstpos(char const *s1, char const *set)
{
	int pos;
	int i;

	i = 0;
	pos = 0;
	while (*s1)
	{
		while (*s1 != set[i])
		{
			if (!set[i])
				return (pos);
			i++;
		}
		i = 0;
		s1++;
		pos++;
	}
	return (pos);
}

static int			lastpos(char const *s1, char const *set)
{
	int pos;
	int i;

	i = 0;
	pos = ft_strlen(s1);
	while (pos--)
	{
		while (s1[pos] != set[i])
		{
			if (!set[i])
				return (pos);
			i++;
		}
		i = 0;
	}
	return (pos);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		i;
	unsigned int		n;
	unsigned int		j;
	char				*str;

	i = 0;
	if (!s1)
		return (0);
	j = firstpos(s1, set);
	n = lastpos(s1, set);
	str = (char*)malloc(n - j + 2);
	if (str == NULL)
		return (NULL);
	while (j < n + 1)
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
