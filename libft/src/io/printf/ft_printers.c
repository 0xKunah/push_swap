/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:44:49 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/21 18:34:15 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printers.h"
#include "../../../includes/string.h"
#include "../../../includes/number.h"

int	ft_printer(char type, va_list args)
{
	if (type == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (type == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (type == 'i' || type == 'd')
		return (ft_print_nbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), type == 'X'));
	else if (type == 'p')
		return (ft_print_pointer(va_arg(args, size_t)));
	else if (type == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_print_char(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	if (s)
		return ((int)write(1, s, ft_strlen(s)));
	return ((int)write(1, "(null)", 6));
}

int	ft_print_nbr(int n)
{
	char		*s;
	ssize_t		len;

	s = ft_itoa(n);
	if (s)
	{
		len = write(1, s, ft_strlen(s));
		free(s);
		return ((int)len);
	}
	return (-1);
}

int	ft_print_str_len(char *s, int len)
{
	if (s)
		return ((int)write(1, s, len));
	return ((int)write(1, "(null)", 6));
}
