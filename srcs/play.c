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

static void	get_mark(t_filler *f, char mark,
float *center_x, float *center_y)
{
	size_t i;

	i = 0;
	while (++i <= f->map->size_y)
	{
		f->i = 0;
		while (++f->i <= f->map->size_x)
		{
			if (f->map->grid[i][f->i] == mark)
			{
				*center_x = f->i;
				*center_y = i;
				return ;
			}
		}
	}
}

static void	res_aim(t_filler *f, t_vec *vec, t_vec *mid)
{
	t_equa	*e;
	t_equa	res;

	e = ft_equanew(0, 0, vec->y / vec->x, 0);
	e->b = mid->y - e->a * mid->x;
	res.y = (e->a != 0) ? (0 - e->b) / e->a : -1;
	res.x = e->a * 0 + e->b;
	res.a = (e->a != 0) ? ((float)FMY - e->b) / e->a : -1;
	res.b = e->a * (float)FMX + e->b;
	f->i = 0;
	if (res.y <= FMX && res.y > 0
	&& (AIM[f->i][0] = res.y))
		AIM[f->i++][1] = 1;
	if (res.x <= FMY && res.x > 0
	&& (AIM[f->i][1] = res.x))
		AIM[f->i++][0] = 1;
	if (res.a <= FMX && res.a > 0
	&& (AIM[f->i][0] = res.a))
		AIM[f->i++][1] = (float)FMY;
	if (res.b <= FMY && res.b > 0
	&& (AIM[f->i][1] = res.b))
		AIM[f->i][0] = (float)FMX;
}

static void	get_aim(t_filler *f)
{
	t_vec	*a;
	t_vec	*b;
	t_vec	*mid;
	t_vec	*vec;

	a = ft_vecnew(0, 0);
	b = ft_vecnew(0, 0);
	get_mark(f, FMEM, &a->x, &a->y);
	get_mark(f, FOPM, &b->x, &b->y);
	if (a->y > b->y)
		ft_swapvec(a, b);
	if (a->y == b->y)
	{
		AIM[0][0] = (b->y - a->y) / 2;
		AIM[0][1] = 0;
		AIM[1][0] = (b->y - a->y) / 2;
		AIM[1][1] = FMY;
		return ;
	}
	mid = ft_getmidcoor(a, b);
	vec = ft_vecnew(mid->x - b->x, mid->y - b->y);
	vec = ft_get_perpendicular_vec(vec, TRUE);
	res_aim(f, vec, mid);
}

int			play(t_filler *f)
{
	if (!f->round)
	{
		get_aim(f);
		get_mark(f, FOPM, &AIM[2][0], &AIM[2][1]);
	}
	return (find_fit(f));
}
