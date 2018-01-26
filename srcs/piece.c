/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 19:19:42 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	init_piece(t_filler *f)
{
	char *line;
	char *s;
	t_piece	*p;

	p = ft_memalloc(sizeof(p));
	get_next_line(0, &line);
	s = line;
	while (!ft_isdigit(*line))
		line++;
	p->size_y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	p->size_x = ft_atoi(line);
	f->i = 0;
	if (!(p->shape = (char**)malloc(sizeof(char*) * (p->size_y + 1))))
		exit(1);
	while (f->i < p->size_y)
		p->shape[f->i++] = ft_strnew(1);
	f->piece = p;

}

void	get_piece(t_filler *f)
{
	char *line;

	int fd = open("res", O_WRONLY | O_APPEND);
	init_piece(f);
	f->i = 0;
	while (f->i < f->piece->size_y)
	{
		get_next_line(0, &line);
		f->piece->shape[f->i++] = ft_strdup(line);
	}
	f->i = 0;
	while (f->i < f->piece->size_y)
		ft_fprintf(fd, "%s\n", f->piece->shape[f->i++]);
}