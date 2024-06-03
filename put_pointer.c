/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaefer <rafaefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:56:17 by rafaefer          #+#    #+#             */
/*   Updated: 2024/06/03 10:52:14 by rafaefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*hex_to_str(unsigned long n, char *base)
{
	int		size;
	char	*hex;

	size = count_hex(n);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[n % 16];
		n = n / 16;
		size--;
	}
	return (hex);
}

int	put_pointer(void *nbr, char *base)
{
	int				len;
	char			*str;
	unsigned long	n;

	if (nbr == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	n = (unsigned long)nbr;
	ft_putstr("0x");
	str = hex_to_str(n, base);
	len = ft_putstr(str);
	free(str);
	return (len + 2);
}
