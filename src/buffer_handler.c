/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:08:02 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/17 11:14:27 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	flush_buff(t_list *lst)
{
	int	size;
	int	len;

	size = 0;
	while (lst)
	{
		len = max(ft_strlen(lst->content), 1);
		write(1, lst->content, len);
		size += len;
		lst = lst->next;
	}
	return (size);
}

int	buffer_manip(char *s, char option)
{
	int				size;
	static t_list	*buffer = NULL;

	size = 0;
	if (option & APPEND)
	{
		if (!s)
			s = "(null)";
		if (s[0] || option & CHAR)
			ft_lstadd_back(&buffer, ft_lstnew(ft_strdup(s)));
		if (option & FREE)
			free(s);
	}
	else if (option & FLUSH)
	{
		size = flush_buff(buffer);
		ft_lstclear(&buffer, &free);
	}
	return (size);
}

void	buffer_manip_char(char c, char option)
{
	char	s[2];

	s[0] = c;
	s[1] = 0;
	buffer_manip(s, option | CHAR);
}
