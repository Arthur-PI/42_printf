/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:37:00 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/14 11:18:10 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		res1;
	int		res2;

	char *p = "wagawga";
	res1 = printf("%p", p);
	putchar('\n');
	res2 = ft_printf("%p", p);
	printf("\nres1 = %d; res2 = %d\n", res1, res2);
	return (0);
}
