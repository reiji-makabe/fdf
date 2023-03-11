/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:46:56 by rmakabe           #+#    #+#             */
/*   Updated: 2023/01/07 16:53:18 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list *ap, char type)
{
	char	c[2];
	char	*str;

	if (type == 'c')
	{
		c[0] = va_arg(*ap, int);
		c[1] = 0;
		return (write(1, c, 1));
	}
	else if (type == 's')
	{
		str = va_arg(*ap, char *);
		return (write(1, str, ft_strlen(str)));
	}
	return (-1);
}

int	print_pointer(size_t num_ptr)
{
	const char	*num = "0123456789abcdef";

	if (num_ptr < 16)
		return (write (1, "0x", 2) + write (1, &num[num_ptr], 1));
	else
	{
		return (print_pointer(num_ptr / 16) + write(1, &num[num_ptr % 16], 1));
	}
}

int	print_decimal(long long num_int)
{
	int			np;
	const char	*num = "0123456789";

	np = 0;
	if (num_int < 0)
	{
		num_int *= -1;
		np++;
		write(1, "-", 1);
	}
	if (num_int < 10)
		return (write(1, num + num_int, 1) + np);
	else
		return (print_decimal(num_int / 10) + \
				write(1, num + num_int % 10, 1) + np);
}

int	print_hex(unsigned int num_hex, char letter)
{
	char	*num;

	if (letter == 'x')
		num = "0123456789abcdef";
	else
		num = "0123456789ABCDEF";
	if (num_hex < 16)
		return (write(1, num + num_hex, 1));
	else
		return (print_hex(num_hex / 16, letter) + \
				write(1, num + num_hex % 16, 1));
}
