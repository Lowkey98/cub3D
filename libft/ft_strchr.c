/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:12:51 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:12:52 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, char x)
{
	while (*str)
	{
		if (*str == x)
			return ((char*)str);
		str++;
	}
	if (!x)
		return ((char*)str);
	return (0);
}
