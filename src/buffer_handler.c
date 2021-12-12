/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:08:02 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/12 17:03:53 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*concat(char *s1, char *s2)
{
	int		size;
	int		s1_size;
	char	*res;

	s1_size = ft_strlen(s1);
	size = s1_size + ft_strlen(s2);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, size + 1);
	ft_strlcpy(res + s1_size, s2, size + 1);
	free(s1);
	return (res);
}

int	buffer_manip(char *s, char option)
{
	static size_t	size = 0;
	static char		*buffer = NULL;

	if (option & APPEND && s)
	{
		size += ft_strlen(s);
		if (!buffer)
			buffer = ft_strdup(s);
		else
			buffer = concat(buffer, s);
		if (option & FREE)
			free(s);
	}
	else if (option & FLUSH)
	{
		ft_putstr_fd(buffer, 1);
		free(buffer);
		buffer = NULL;
	}
	return (size);
}

void	buffer_manip_char(char c, char option)
{
	char	s[2];

	s[0] = c;
	s[1] = 0;
	buffer_manip(s, option);
}
