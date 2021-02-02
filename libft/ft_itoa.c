/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:11:27 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:11:29 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intlen(int n)
{
	if (n)
		return (1 + intlen(n / 10));
	return (1);
}

static char		*zero(void)
{
	char *str;

	str = malloc(2);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char				*str;
	unsigned int		m;
	int					len;

	if (n == 0)
		return (zero());
	len = intlen(n);
	if (n < 0)
	{
		n = n * -1;
		len = len + 1;
	}
	str = (char *)malloc(len);
	m = n;
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str[len - 1] = '\0';
	while (m)
	{
		str[len - 2] = m % 10 + 48;
		m = m / 10;
		len--;
	}
	return (str);
}
