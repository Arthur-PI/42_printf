/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:45:09 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/14 16:08:00 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_options(char c)
{
	int		i;
	char	*options;

	i = 0;
	options = OPTIONS;
	while (options[i])
	{
		if (c == options[i])
			return (1);
		i++;
	}
	return (0);
}

void	handle_option(char c, va_list arg)
{
	if (c == O_PERCENT)
		buffer_manip("%", APPEND);
	else if (c == O_CHAR)
		option_char(va_arg(arg, int));
	else if (c == O_STRING)
		option_string(va_arg(arg, char *));
	else if (c == O_POINTER)
		option_pointer(va_arg(arg, void *));
	else if (c == O_DECIMAL)
		option_int(va_arg(arg, int));
	else if (c == O_INT)
		option_int(va_arg(arg, int));
	else if (c == O_UINT)
		option_uint(va_arg(arg, unsigned int));
	else if (c == O_HEX)
		option_hex(va_arg(arg, unsigned int));
	else if (c == O_HEXMAJ)
		option_hexcaps(va_arg(arg, unsigned int));
}

int	start_option(const char *s, va_list arg)
{
	int	i;

	i = 1;
	while (s[i] && !is_options(s[i]))
		i++;
	if (s[i])
		handle_option(s[i++], arg);
	return (i);
}

int	printf_handle_args(const char *format, va_list arg)
{
	int		i;
	int		start;

	i = 0;
	while (format[i])
	{
		start = i;
		while (format[i] && format[i] != '%')
			i++;
		buffer_manip(ft_substr(format, start, i - start), APPEND | FREE);
		if (format[i] == '%')
			i += start_option(format + i, arg);
	}
	return (buffer_manip(NULL, FLUSH));
}

int	ft_printf(const char *format, ...)
{
	int		bytes;
	va_list	arg;

	va_start(arg, format);
	bytes = printf_handle_args(format, arg);
	va_end(arg);
	return (bytes);
}
