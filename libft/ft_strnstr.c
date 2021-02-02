/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:13:40 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:13:41 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (!*little)
		return ((char*)big);
	while (len && big[j])
	{
		while (j < len && big[j] == little[i])
		{
			j++;
			i++;
			if (!little[i])
				return ((char*)big - i + j);
		}
		j = j - i;
		i = 0;
		j++;
	}
	return (NULL);
}
