/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:15:38 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/14 16:09:33 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	option_int(int n)
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
		option_int(nbr / 10);
		buffer_manip_char(nbr % 10 + '0', APPEND);
	}
}

void	option_uint(unsigned int n)
{
	if (n < 10)
		buffer_manip_char(n % 10 + '0', APPEND);
	else
	{
		option_uint(n / 10);
		buffer_manip_char(n % 10 + '0', APPEND);
	}
}
