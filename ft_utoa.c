/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaefer <rafaefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:55:46 by rafaefer          #+#    #+#             */
/*   Updated: 2024/06/03 11:05:55 by rafaefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(unsigned int nbr)
{
	int len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*str_new(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	nbr;
	int				len;
	char			*str;

	len = nbr_len(n);
	str = str_new(len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	nbr = n;
	while (len--)
	{
		str[len] = 48 + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}
