/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/04 16:09:42 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

#define AIMY AIM[2][0]
#define AIMX AIM[2][1]
#define XY (x > 1 && y > 1)
#define YX (x < (int)FMX && y < (int)FMY)
#define RETY f->by - (int)FPDY - 1
#define RETX f->bx - (int)FPDX - 1

static inline void	check_surr(t_filler *f, int x, int y)
{
	IF(XY && YX && FMG[y - 1][x - 1] == '.', FMG[y - 1][x - 1] = '*');
	IF(XY && YX && FMG[y - 1][x] == '.', FMG[y - 1][x] = '*');
	IF(XY && YX && FMG[y - 1][x + 1] == '.', FMG[y - 1][x + 1] = '*');
	IF(XY && YX && FMG[y][x - 1] == '.', FMG[y][x - 1] = '*');
	IF(XY && YX && FMG[y][x + 1] == '.', FMG[y][x + 1] = '*');
	IF(XY && YX && FMG[y + 1][x - 1] == '.', FMG[y + 1][x - 1] = '*');
	IF(XY && YX && FMG[y + 1][x] == '.', FMG[y + 1][x] = '*');
	IF(XY && YX && FMG[y + 1][x + 1] == '.', FMG[y + 1][x + 1] = '*');
}

void				get_surr(t_filler *f, char mark)
{
	int x;
	int y;

	y = 0;
	while (++y <= (int)FMY)
	{
		x = 0;
		while (++x <= (int)FMX)
			if (FMG[y][x] == mark)
				check_surr(f, x, y);
	}
}

static inline void	check_pow(t_filler *f, int *pow, int x, int y)
{
	if (POW2(y - (int)f->fits[f->i][0])
	+ POW2(x - (int)f->fits[f->i][1]) < (int)*pow)
	{
		*pow = POW2(y - (int)f->fits[f->i][0])
		+ POW2(x - (int)f->fits[f->i][1]);
		f->bx = f->fits[f->i][1];
		f->by = f->fits[f->i][0];
	}
	f->i++;
}

static int			f_bfit(t_filler *f, int pos)
{
	int y;
	int x;
	int pow;

	y = 0;
	pow = POW2(FMY) + POW2(FMX);
	while (++y <= (int)FMY)
	{
		x = 0;
		f->i = 0;
		while (++x <= (int)FMX)
			if (FMG[y][x] == '*')
				while (f->i < (size_t)pos)
					check_pow(f, &pow, x, y);
	}
	if (f->bx && f->by)
		return (ft_printf("%d %d\n", RETY, RETX));
	return (0);
}

int					find_fit(t_filler *f)
{
	int y;
	int x;
	int pos;

	y = 0;
	pos = 0;
	f->bx = 0;
	f->by = 0;
	get_surr(f, FOPM);
	while (++y <= (int)FMY)
	{
		x = 0;
		while (++x <= (int)FMX)
			if (p_fits(f, x, y))
			{
				f->fits[pos][0] = y;
				f->fits[pos++][1] = x;
			}
	}
	if (pos)
		return (f_bfit(f, pos));
	return (0);
}
