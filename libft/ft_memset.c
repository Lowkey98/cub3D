/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:12:05 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:12:06 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	void		*dup;
	size_t		i;

	i = 0;
	dup = str;
	while (i < n)
	{
		((unsigned char*)str)[i] = c;
		i++;
	}
	return (dup);
}
