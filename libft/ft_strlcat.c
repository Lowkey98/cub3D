/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:13:15 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:13:16 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t a;
	size_t j;

	j = 0;
	if (n == 0)
		return (ft_strlen(src));
	a = ft_strlen(src);
	i = ft_strlen(dst);
	if (n > i)
		a = a + i;
	else
	{
		a = a + n;
		return (a);
	}
	while (i + 1 < n && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (a);
}
