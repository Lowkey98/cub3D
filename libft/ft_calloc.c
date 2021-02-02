/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:10:55 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:10:56 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	int		i;

	i = 0;
	if (!(ptr = malloc(nitems * size)))
		return (0);
	while ((int)(nitems * size) > i)
	{
		*(char*)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
