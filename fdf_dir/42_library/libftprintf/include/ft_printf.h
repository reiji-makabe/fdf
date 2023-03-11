/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:40:38 by rmakabe           #+#    #+#             */
/*   Updated: 2023/01/07 16:26:02 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *fmt, ...);
int	print_string(va_list *ap, char type);
int	print_pointer(size_t num_ptr);
int	print_decimal(long long num_int);
int	print_hex(unsigned int num_hex, char letter);

#endif
