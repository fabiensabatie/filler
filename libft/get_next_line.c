/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:09:53 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:55:24 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*find_list(t_list *list, int fd)
{
	while (fd != (int)list->content_size)
	{
		if (list->next)
			list = list->next;
		else
		{
			list->next = ft_lstnew(ft_strdup(""), fd);
			list = list->next;
		}
	}
	return (list);
}

static int			check_line(char **content, char **copy, char **line)
{
	if (!(**copy) && !ft_strchr(*copy, '\n'))
		return (0);
	free(*content);
	if (ft_strchr(*copy, '\n'))
	{
		*line = ft_strcsub(*copy, '\n');
		*content = ft_strdup(ft_strchr(*copy, '\n') + 1);
	}
	else
	{
		*line = ft_strdup(*copy);
		*content = ft_strdup("");
	}
	free(*copy);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	char			buffer[BUFF_SIZE + 1];
	char			*copy;
	int				ret;

	if (fd < 0 || BUFF_SIZE < 1 || read(fd, "", 0) || !line)
		return (-1);
	list = !list ? ft_lstnew(ft_strdup(""), fd) : list;
	copy = ft_strdup(find_list(list, fd)->content);
	while (!ft_strchr(copy, '\n') && (ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = 0;
		copy = ft_strjoinfree(copy, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (check_line((char**)&(find_list(list, fd)->content),
	&copy, line));
}