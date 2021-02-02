/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:13:06 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:13:07 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char *dst;

	dst = malloc(ft_strlen(s) + 1);
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, (char *)s);
	return (dst);
}
