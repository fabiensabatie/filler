/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/01 13:19:36 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		p_fits(t_filler *f, int x, int y)
{
	size_t i;
	int sp;

	sp = 0;
	i = (size_t)FPDY;
	int fd = open("res", O_WRONLY | O_APPEND);
	int ret;
	while (i < FPY && y < FMY)
	{
		f->i = FPDX;
		while (f->i < FPX && x < FMX)
		{
			if (FPS[i][f->i] == '*')
			{
				ft_dprintf(fd, "On map at : %d %d\n", x- 1, y-1);
				if (FMG[y][x] == f->me->mark && !sp)
					sp++;
				else if (FMG[y][x] != '.')
				{
					ft_dprintf(fd, "Could not fit\n");
					return (0);
				}
			}
			else
				ft_dprintf(fd, "- On map at : %d %d\n", x-1, y-1);
			x++;
			f->i++;
		}
		y++;
		i++;
	}
	ret = (sp) ? 1 : 0;
	return (ret);
}

void	init_p(t_filler *f)
{
	char	*line;
	char	*s;
	size_t	i;

	i = 0;
	get_next_line(0, &line);
	s = line;
	FPY = ft_atoi(ft_strstr(line, " "));
	line = ft_strstr(line, " ") + 1;
	while (ft_isdigit(*line))
		line++;
	FPX = ft_atoi(line);
	free(s);
	P_ALLOC(FPS, char**, (sizeof(char*) * (FPY + 1)))
	while (i < FPY)
		P_ALLOC(FPS[i++], char*, (FPX + 1))
}

void	get_piece(t_filler *f)
{
	char	*line;
	size_t	i;

	i = 0;
	init_p(f);
	FPDY = -1;
	FPDX = (int)FPX;
	while (i < FPY && get_next_line(0, &line))
	{
		FPDX = (FPDX > ft_strcpos(line, '*')) ? ft_strcpos(line, '*') : FPDX;
		if (FPDY == -1)
			FPDY = (ft_strcpos(line, '*') != (int)ft_strlen(line)) ? i : FPDY;
		ft_strcpy(FPS[i++], line);
		free(line);
	}
}
