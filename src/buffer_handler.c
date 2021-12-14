/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:08:02 by apigeon           #+#    #+#             */
/*   Updated: 2021/12/14 10:39:34 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static char	*concat(char *s1, char *s2)
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
}*/

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
		if (s[0] != 0 || option & CHAR)
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
