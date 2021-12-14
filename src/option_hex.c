/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:15:01 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/14 16:10:05 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	tohex(unsigned int n, char *base, unsigned int len)
{
	if (n < len)
		buffer_manip_char(base[n % len], APPEND);
	else
	{
		tohex(n / len, base, len);
		buffer_manip_char(base[n % len], APPEND);
	}
}

void	option_hex(unsigned int n)
{
	tohex(n, BASE16, ft_strlen(BASE16));
}

void	option_hexcaps(unsigned int n)
{
	tohex(n, BASE16_CAPS, ft_strlen(BASE16_CAPS));
}
