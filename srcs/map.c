/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/28 17:14:51 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	print_map(t_filler *f)
{
	size_t i;
	int fd = open("res", O_WRONLY | O_APPEND);

	i = 1;
	while (i <= f->map->size_y)
	{
		f->i = 1;
		while (f->i <= f->map->size_x)
		{
			dprintf(fd, "%c", f->map->grid[i][f->i]);
			f->i++;
		}
		dprintf(fd, "\n");
		i++;
	}
}

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

static void init_map(t_filler *f)
{
	size_t i;

	i = 1;
	P_ALLOC(f->map->grid, char**, (sizeof(char*) * (f->map->size_y + 1)))
	while (i <= f->map->size_y)
		P_ALLOC(f->map->grid[i++], char*, (f->map->size_x + 2))
}

void		get_map(t_filler *f)
{
	char	*line;
	char	*cat;
	size_t	i;

	if (!f->round && get_msize(f))
		init_map(f);
	get_next_line(0, &line);
	free(line);
	f->i = 1;
	i = 1;
	int fd = open("res", O_WRONLY | O_APPEND);
	while (i <= f->map->size_y && get_next_line(0, &line))
	{
		while (ft_isdigit(line[f->i]) || line[f->i] == ' ')
			f->i++;
		cat = ft_strjoin(" ", line + f->i);
		ft_strcpy(f->map->grid[i++], cat);
		dprintf(fd, "Line: %s\n", f->map->grid[i - 1]);
		free(line);
		free(cat);
	}
}
