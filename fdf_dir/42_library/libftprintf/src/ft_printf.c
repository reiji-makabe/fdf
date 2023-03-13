/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:04:57 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/10 00:04:27 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(va_list *ap, char type);
static int	print_while_fmt(va_list *ap, const char *fmt);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		re;

	re = 0;
	va_start(ap, fmt);
	re = print_while_fmt(&ap, fmt);
	va_end(ap);
	return (re);
}

static int	print_while_fmt(va_list *ap, const char *fmt)
{
	int	re;
	int	tmp;

	re = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			tmp = print_arg(ap, *++fmt);
		else
			tmp = write(1, fmt, 1);
		if (tmp < 0)
			return (-1);
		re += tmp;
		fmt++;
	}
	return (re);
}

static int	print_arg(va_list *ap, char type)
{
	if (type == 'c' || type == 's')
		return (print_string(ap, type));
	else if (type == 'p')
		return (print_pointer(va_arg(*ap, size_t)));
	else if (type == 'd' || type == 'i')
		return (print_decimal(va_arg(*ap, int)));
	else if (type == 'x' || type == 'X' || type == 'u')
		return (print_hex(va_arg(*ap, unsigned int), type));
	else if (type == '%')
		return (write(1, &"%", 1));
	else
		return (-1);
}
