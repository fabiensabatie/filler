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

static int	get_msize(t_filler *f)
{
	char *line;
	char *s;

	get_next_line(0, &line);
	s = line;
	FMY = ft_atoi(ft_strstr(line, " "));
	line = ft_strstr(line, " ") + 1;
	while (ft_isdigit(*line))
		line++;
	FMX = ft_atoi(line);
	free(s);
	return (1);
}

void		get_map(t_filler *f)
{
	char	*line;
	char	*cat;
	size_t	i;

	i = 1;
	if (get_msize(f) && !f->round)
	{
		P_ALLOC(FMG, char**, (sizeof(char*) * (FMY + 1)));
		while (i <= FMY)
			P_ALLOC(FMG[i++], char*, (FMX + 2));
	}
	get_next_line(0, &line);
	free(line);
	f->i = 1;
	i = 1;
	while (i <= FMY && get_next_line(0, &line))
	{
		while (ft_isdigit(line[f->i]) || line[f->i] == ' ')
			f->i++;
		cat = ft_strjoin(" ", line + f->i);
		ft_strcpy(FMG[i++], cat);
		free(line);
		free(cat);
	}
}
