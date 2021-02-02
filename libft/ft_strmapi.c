/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:13:29 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:13:30 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char							*str;
	int								len;
	unsigned int					i;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	while (len--)
	{
		str[i] = f(i, *s);
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
