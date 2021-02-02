/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:10:41 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:10:42 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	int		a;
	long	somme;

	i = 0;
	a = 1;
	somme = 0;
	while (str[i] <= 32 && str[i] > 0)
		if (str[i++] == 27)
			return (0);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			a = -1;
	while (str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'))
	{
		if ((somme * a) < -2147483648)
			return (0);
		if ((somme * a) > 2147483647)
			return (-1);
		somme = (str[i++] - '0') + somme * 10;
	}
	return (a * somme);
}
