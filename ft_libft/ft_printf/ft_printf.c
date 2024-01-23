/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:10:28 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/25 14:54:24 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
	In a 64bits system the size of a pointer is a 8bits : unsigned long long
*/

/*
	int	print_char(char c);
	int	print_str(char *str);
	int	print_ptr(unsigned long long ptr);
*/
// Les fonctions print_char, print_str, print_ptr, print_number, print_unsigned,
// print_hex_lowercase,
//	print_hex_uppercase et print_percent doivent être définies.
static int	ft_formats(va_list args, const char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += print_char(va_arg(args, int));
	else if (c == 's')
		length += print_str(va_arg(args, char *));
	else if (c == 'p')
		length += print_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		length += print_nbr(va_arg(args, int));
	else if (c == 'u')
		length += print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		length += print_hex_lowercase(va_arg(args, unsigned int));
	else if (c == 'X')
		length += print_hex_uppercase(va_arg(args, unsigned int));
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	va_start(args, format);
	length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				length += print_char('%');
				format++;
			}
			else
			{
				length += ft_formats(args, *(++format));
			}
		}
		else
			length += print_char(*format);
		format++;
	}
	return (va_end(args), length);
}
