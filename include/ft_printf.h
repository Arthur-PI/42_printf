/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:20:06 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/14 11:13:16 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>


# include <stdio.h>

# define APPEND	0b0001
# define FLUSH	0b0010
# define FREE	0b0100
# define CHAR	0b1000

# define OPTIONS "cspdiuxX%"
# define O_CHAR 'c'
# define O_STRING 's'
# define O_POINTER 'p'
# define O_DECIMAL 'd'
# define O_INT 'i'
# define O_UINT 'u'
# define O_HEX 'x'
# define O_HEXMAJ 'X'
# define O_PERCENT '%'

# define CAPS 1
# define NO_CAPS 0

# define BASE16 "0123456789abcdef"
# define BASE16_CAPS "0123456789ABCDEF"

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

int		ft_printf(const char *format, ...);
int		buffer_manip(char *s, char option);
void	buffer_manip_char(char c, char option);

#endif
