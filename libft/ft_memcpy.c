/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:11:54 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:11:55 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char		*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	s = (unsigned char*)str2;
	d = (unsigned char*)str1;
	if (d == s)
		return (d);
	if ((!s && !d))
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
