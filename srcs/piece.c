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

static int	get_psize(t_filler *f)
{
	char* line;
	char *s;

	get_next_line(0, &line);
	s = line;
	f->p->size_y = ft_atoi(ft_strstr(line, " "));
	line = ft_strstr(line, " ") + 1;
	while (ft_isdigit(*line))
		line++;
	f->p->size_x = ft_atoi(line);
	free(s);
	return (1);
}

void		get_piece(t_filler *f)
{
	char	*line;
	size_t	i;

	i = 0;
	get_psize(f);
	P_ALLOC(f->p->shape, char**, (sizeof(char*) * (f->p->size_y + 1)))
	while (i < f->p->size_y)
		P_ALLOC(f->p->shape[i++], char*, (f->p->size_x + 1))
	f->i = 0;
	i = 0;
	while (i < f->p->size_y && get_next_line(0, &line))
	{
		ft_strcpy(f->p->shape[i++], line);
		free(line);
	}
}