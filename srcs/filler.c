/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/19 17:59:41 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	get_map(t_filler *f)
{
	size_t	i;
	char	*line;

	i = 0;
	int fd = open("res", O_WRONLY | O_APPEND);
	if (!(f->map = (char**)ft_memalloc(f->map_y + 1)))
		exit(1);
	get_next_line(0, &line);
	free(line);
	while (i < f->map_y)
	{
		get_next_line(0, &line);
		while (ft_isdigit(*line) || *line == ' ')
			line++;
		f->map[i++] = ft_strdup(line);
	}
	i = 0;
	while (i < f->map_y)
		ft_fprintf(fd, "%s\n", f->map[i++]);
}

void	set_f(t_filler *f)
{
	char	*line;

	get_next_line(0, &line);
	f->me->player = ft_atoi(line + 10);
	free(line);
	get_next_line(0, &line);
	f->map_y = ft_atoi(line + 8);
	f->map_x = ft_atoi(line + 10);
	f->me->mark = (f->me->player == P1) ? "oO" : "xX";
	free(line);
}



int			main(void)
{
	t_filler	f;
	t_champ		champ;

	ft_bzero(&f, sizeof(f));
	ft_bzero(&champ, sizeof(champ));
	f.me = &champ;
	set_f(&f);
	get_map(&f);
	// int fd = open("res", O_WRONLY | O_APPEND);
	// dprintf(fd, "%s\n", f.map[0]);
	// dprintf(fd, "%s\n", f.map[1]);
	// dprintf(fd, "%s\n", f.map[2]);
	// dprintf(fd, "%s\n", f.map[3]);
	// dprintf(fd, "%s\n", f.map[4]);
	// dprintf(fd, "%s\n", f.map[5]);
	// dprintf(fd, "%s\n", f.map[6]);
	// dprintf(fd, "%s\n", f.map[7]);

}
