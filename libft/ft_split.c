/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	ft_split.c										 :+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <marvin@42.fr>					 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/13 16:46:54 by ayafdel			#+#	#+#			 */
/*	Updated: 2019/10/24 22:47:05 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int		numofstr(char const *s, char c)
{
	int cpt;

	cpt = 0;
	while (*s)
	{
		if ((*(s + 1) == '\0' || *(s + 1) == c) && *s != c)
			cpt++;
		s++;
	}
	return (cpt);
}

static int		numofchar(char const *s, char c)
{
	int cpt;

	cpt = 0;
	if (*(char *)s == c)
		return (0);
	while (*(char *)s != c && *(char *)s != '\0')
	{
		s++;
		cpt++;
	}
	return (cpt);
}

static char		*fillstr(char const *s, int j)
{
	int			i;
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = 0;
	while (i != j)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		**ft_free(char **tab, int j)
{
	while (j)
	{
		j--;
		free(tab[j]);
	}
	free(tab);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		n;

	j = 0;
	i = 0;
	if (!s)
		return (0);
	n = numofstr(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (n--)
	{
		while (!(j = numofchar(s, c)))
			s++;
		if (!(tab[i] = fillstr(s, j)))
			return (ft_free(tab, i));
		s = s + j;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
