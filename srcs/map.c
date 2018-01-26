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

static t_map	*get_msize(t_filler *f)
{
	t_map	*m;
	char *l;

	P_ALLOC(m, t_map*, sizeof(m));
	get_next_line(0, &l);
	m->size_y = ft_atoi(l + 8);
	f->i = 0;
	while (ft_isdigit(*(l + 8 + f->i)))
		f->i++;
	m->size_x = ft_atoi(l + 8 + f->i);
	free(l);
	return (m);
}

static t_map	*init_map(t_filler *f)
{
	t_map	*m;

	m = get_msize(f);
	P_ALLOC(m->grid, char**, (sizeof(char*) * m->size_y + 1));
	f->i = 0;
	while (f->i < m->size_y)
		P_ALLOC(m->grid[f->i++], char*, (m->size_x + 1));
	return (m);
}

void	get_map(t_filler *f)
{
	char *line;
	size_t i;

	i = 0;
	if (!f->round)
		f->map = init_map(f);
	get_next_line(0, &line);
	free(line);

	while (i < f->map->size_y)
	{
		f->i = 0;
		get_next_line(0, &line);
		while (ft_isdigit(line[f->i]) || line[f->i] == ' ')
			f->i++;
		ft_strcpy(f->map->grid[i++], line + f->i);
		free(line);
	}
}