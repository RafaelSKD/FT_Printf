/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaefer <rafaefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:52:12 by rafaefer          #+#    #+#             */
/*   Updated: 2024/05/17 12:22:31 by rafaefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		putnbr_u(unsigned int nbr);
int		put_pointer(void *nbr, char *base);
int		put_hex(unsigned int nbr, char *base);

#endif