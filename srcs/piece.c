/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/05 14:22:42 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

#define AIMY AIM[2][0]
#define AIMX AIM[2][1]
#define XY (AIMX > 1 && AIMY > 1)
#define YX (AIMX < (int)FMX && AIMY < (int)FMY)

int		get_surr(t_filler *f, char mark)
{

	AIMY = 0;
	while (++AIMY <= (int)FMY)
	{
		AIMX = 0;
		while (++AIMX <= (int)FMX)
			if (FMG[(int)AIMY][(int)AIMX] == mark)
			{
				IFRET (XY && YX && FMG[(int)AIMY - 1][(int)AIMX - 1] == '.', 1);
				IFRET (XY && YX && FMG[(int)AIMY - 1][(int)AIMX] == '.', 1);
				IFRET (XY && YX && FMG[(int)AIMY - 1][(int)AIMX + 1] == '.', 1);
				IFRET (XY && YX && FMG[(int)AIMY][(int)AIMX - 1] == '.', 1);
				IFRET (XY && YX && FMG[(int)AIMY][(int)AIMX + 1] == '.', 1);
				IFRET (XY && YX && FMG[(int)AIMY + 1][(int)AIMX - 1] == '.', 1);
				IFRET (XY && YX && FMG[(int)AIMY + 1][(int)AIMX] == '.', 1);
				IFRET (XY && YX && FMG[(int)AIMY + 1][(int)AIMX + 1] == '.', 1);
			}
	}
	return (0);
}

static int	p_fits(t_filler *f, int x, int y)
{
	t_equa coor;
	size_t stars;

	stars = FPW;
	coor.y = FPDY - 1;
	coor.b = y - 1;
	f->i = 0;
	while (++coor.y < FPY)
	{
		IFRET(++coor.b > FMY, 0);
		coor.x = FPDX - 1;
		coor.a = x - 1;
		while (++coor.x < FPX)
		{
			IFRET(++coor.a > FMX, 0);
			if (FPS[(int)coor.y][(int)coor.x] == '*')
			{
				IFRET(FMG[(int)coor.b][(int)coor.a] == FOPM, 0);
				IFRET(f->i && FMG[(int)coor.b][(int)coor.a] == FMEM, 0);
				IF(!f->i && FMG[(int)coor.b][(int)coor.a] == FMEM, f->i++);
				IFRET(--stars == 0, f->i);
			}
		}
	}
	return (f->i);
}

int			find_fit(t_filler *f)
{
	int y;
	int x;
	int bx;
	int by;
	int pos;
	size_t	pow;

	y = 0;
	bx = 0;
	by = 0;
	pos = 0;
	pow = POW2(FMY) + POW2(FMX);
	IF (!pos && FMG[(int)AIM[0][1]][(int)AIM[0][0]] != '.', pos++);
	IF (pos == 1 && FMG[(int)AIM[1][1]][(int)AIM[1][0]] != '.', pos++);
	//get_surr(f, FOPM);
	while (++y <= (int)FMY)
	{
		x = 0;
		while (++x <= (int)FMX)
			if (p_fits(f, x, y))
				if (POW2(y - (int)AIM[pos][1]) + POW2(x - (int)AIM[pos][0]) < (int)pow)
				{
					pow = POW2(y - (int)AIM[pos][1]) + POW2(x - (int)AIM[pos][0]);
					bx = x;
					by = y;
				}
	}
	if (bx != 0 && by != 0)
		return ft_printf("%d %d\n", by - (int)FPDY - 1, bx - (int)FPDX - 1);
	return (0);
}

void		init_p(t_filler *f)
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
	P_ALLOC(FPS, char**, (sizeof(char*) * (FPY + 1)));
	while (i < FPY)
		P_ALLOC(FPS[i++], char*, (FPX + 1));
}

void		get_piece(t_filler *f)
{
	char	*line;
	size_t	i;

	i = 0;
	init_p(f);
	FPDY = -1;
	FPDX = (int)FPX;
	FPW = 0;
	while (i < FPY && get_next_line(0, &line))
	{
		FPDX = (FPDX > ft_strcpos(line, '*')) ? ft_strcpos(line, '*') : FPDX;
		if (FPDY == -1)
			FPDY = (ft_strcpos(line, '*') < (int)ft_strlen(line)) ? i : FPDY;
		ft_strcpy(FPS[i], line);
		FPW += ft_strcount(FPS[i++], '*');
		free(line);
	}
}
