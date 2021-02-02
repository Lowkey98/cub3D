/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:13:10 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:13:11 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_starjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
		return (0);
	str = malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
