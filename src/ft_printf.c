/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:45:09 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/12 17:10:30 by apigeon          ###   ########.fr       */
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

char	*stradress(void *p)
{
	(void)p;
	return (NULL);
}

void	stritoa(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		buffer_manip("-", APPEND);
		nbr = -nbr;
	}
	if (nbr < 10)
		buffer_manip_char(nbr % 10 + '0', APPEND);
	else
	{
		stritoa(nbr / 10);
		buffer_manip_char(nbr % 10 + '0', APPEND);
	}
}

void	tohexa(int n, int option)
{
	unsigned int	nbr;
	char			*base16[2];

	base16[NO_CAPS] = "0123456789abcdef";
	base16[CAPS] = "0123456789ABCDEF";
	nbr = n;
	if (nbr < 16)
		buffer_manip_char(base16[option][nbr % 16], APPEND);
	else
	{
		tohexa(nbr / 16, option);
		buffer_manip_char(base16[option][nbr % 16], APPEND);
	}
}

void	handle_option(char c, va_list arg)
{
	if (c == O_PERCENT)
		buffer_manip("%", APPEND);
	else if (c == O_CHAR)
		buffer_manip_char(va_arg(arg, int), APPEND);
	else if (c == O_STRING)
		buffer_manip(va_arg(arg, char *), APPEND);
	else if (c == O_POINTER)
		buffer_manip(stradress(va_arg(arg, void *)), APPEND);
	else if (c == O_DECIMAL)
		stritoa(va_arg(arg, int));
	else if (c == O_INT)
		stritoa(va_arg(arg, int));
	else if (c == O_HEX)
		tohexa(va_arg(arg, int), NO_CAPS);
	else if (c == O_HEXMAJ)
		tohexa(va_arg(arg, int), CAPS);
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
	return(buffer_manip(NULL, FLUSH));
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
