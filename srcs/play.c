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

void		get_surr(t_filler *f, char mark)
{
	int x;
	int y;

	y = 0;
	while (++y <= (int)FMY)
	{
		x = 0;
		while (++x <= (int)FMX)
		{
			if (FMG[y][x] == mark)
			{
				IF (XY && YX && FMG[y - 1][x - 1] == '.', FMG[y - 1][x - 1] = '*');
				IF (XY && YX && FMG[y - 1][x] == '.', FMG[y - 1][x] = '*');
				IF (XY && YX && FMG[y - 1][x + 1] == '.', FMG[y - 1][x + 1] = '*');
				IF (XY && YX && FMG[y][x - 1] == '.', FMG[y][x - 1] = '*');
				IF (XY && YX && FMG[y][x + 1] == '.', FMG[y][x + 1] = '*');
				IF (XY && YX && FMG[y + 1][x - 1] == '.', FMG[y + 1][x - 1] = '*');
				IF (XY && YX && FMG[y + 1][x] == '.', FMG[y + 1][x] = '*');
				IF (XY && YX && FMG[y + 1][x + 1] == '.', FMG[y + 1][x + 1] = '*');
			}
		}
	}
}

int			play(t_filler *f)
{
	get_surr(f, FOPM);
	return (find_fit(f));
}
