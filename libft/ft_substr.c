/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:13:52 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:13:53 by ayafdel          ###   ########.fr       */
/*                                                                            */
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
