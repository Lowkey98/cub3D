/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:12:01 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:12:02 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int i;

	i = 0;
	if (!str2 && !str1)
		return (0);
	if (str2 > str1)
	{
		while (n--)
		{
			((char*)str1)[i] = ((char*)str2)[i];
			i++;
		}
	}
	if (str1 > str2)
		while (n--)
			((char*)str1)[n] = ((char*)str2)[n];
	return (str1);
}
