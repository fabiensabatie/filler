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

static void	get_msize(t_filler *f)
{
	char	*line;
	char	*s;

	get_next_line(0, &line);
	s = line;
	while(!ft_isdigit(*line))
		line++;
	f->map->size_y = ft_atoi(line);
	while(ft_isdigit(*line))
		line++;
	f->map->size_x = ft_atoi(line);
	get_next_line(0, &line);
	//free(s);
	//free(line);
}

static void	init_map(t_filler *f)
{
	char **map;

	f->i = 0;
	get_msize(f);
	if (!f->round)
	{
		if (!(map = (char**)malloc(sizeof(char*) * (f->map->size_y + 1))))
			exit(1);
		while (f->i < f->map->size_y)
			map[f->i++] = ft_strnew(1);
		f->map->grid = map;
	}
}

void	get_map(t_filler *f)
{
	char	*line;
	char	*s;
	size_t	i;

	i = 0;
	init_map(f);
	f->i = 0;
	while (f->i < f->map->size_y && f->round < 1)
	{
		get_next_line(0, &line);
		s = line;
		while (ft_isdigit(*line) || *line == ' ')
			line++;
		//free(f->map->grid[f->i]);
		f->map->grid[f->i++] = ft_strdup(line);
	}
}