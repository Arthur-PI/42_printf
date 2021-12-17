/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:15:58 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/14 16:33:21 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	tohexa_pointer(size_t addr)
{
	char	*base16;

	base16 = BASE16;
	if (addr < 16)
		buffer_manip_char(base16[addr % 16], APPEND);
	else
	{
		tohexa_pointer(addr / 16);
		buffer_manip_char(base16[addr % 16], APPEND);
	}
}

void	option_pointer(void *p)
{
	buffer_manip("0x", APPEND);
	tohexa_pointer((size_t) p);
}
