/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:13:44 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:13:45 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = ft_strlen((char*)str);
	while (str[i] != c)
	{
		if (!i)
			return (0);
		i--;
	}
	return ((char*)(str + i));
}
