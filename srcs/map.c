/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 19:19:07 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	get_msize(t_filler *f)
{
	char* line;
	char *s;

	get_next_line(0, &line);
	s = line;
	f->map->size_y = ft_atoi(ft_strstr(line, " "));
	line = ft_strstr(line, " ") + 1;
	while (ft_isdigit(*line))
		line++;
	f->map->size_x = ft_atoi(line);
	free(s);
	return (1);
}

void		get_map(t_filler *f)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!f->round && get_msize(f))
	{
		P_ALLOC(f->map->grid, char**, (sizeof(char*) * (f->map->size_y + 1)))
		while (i < f->map->size_y)
			P_ALLOC(f->map->grid[i++], char*, (f->map->size_x + 1))
	}
	get_next_line(0, &line);
	free(line);
	f->i = 0;
	i = 0;
	while (i < f->map->size_y && get_next_line(0, &line))
	{
		while (ft_isdigit(line[f->i]) || line[f->i] == ' ')
			f->i++;
		ft_strcpy(f->map->grid[i++], line + f->i);
		free(line);
	}
}