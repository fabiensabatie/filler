/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/29 00:40:42 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	get_mark(t_filler *f, char mark,
float *center_x, float *center_y)
{
	size_t i;
	int fd = open("res", O_WRONLY | O_APPEND);

	i = 1;
	while (i <= f->map->size_y)
	{
		f->i = 1;
		while (f->i <= f->map->size_x)
		{
			if (f->map->grid[i][f->i] == mark)
			{
				*center_x = f->i;
				*center_y = i;
				dprintf(fd, "grid[%li][%li] = %c\n", i, f->i, f->map->grid[i][f->i]);
				return ;
			}
			f->i++;
		}
		i++;
	}
}

static void	res_aim(t_filler *f, t_vec *vec, t_vec *mid)
{
	t_equa *e;
	float x_z;
	float x_X;
	float y_z;
	float y_Y;
	float coord[2][2];
	int fd = open("res", O_WRONLY | O_APPEND);

	e = ft_equanew(0, 0, vec->y / vec->x, 0);
	e->b = mid->y - e->a * mid->x;
	dprintf(fd, "The equation is: y = %fx + %f\n", e->a, e->b);
	x_z = (e->a != 0) ? (0 - e->b) / e->a : -1;
	y_z = e->a * 0 + e->b;
	x_X = (e->a != 0) ? ((float)f->map->size_y - e->b) / e->a : -1;
	y_Y = e->a * (float)f->map->size_x + e->b;
	f->i = 0;
	dprintf(fd, "x_z = %1.f\ny_z = %1.f\nx_X = %1.f\ny_Y = %1.f\n", x_z, y_z, x_X, y_Y);
	dprintf(fd, "MAP_SIZE: %ld %ld\n", f->map->size_x, f->map->size_y);
	if (x_z <= f->map->size_x && x_z > 0
	&& (coord[f->i][0] = x_z))
		coord[f->i++][1] = 0;
	if (y_z <= f->map->size_y && y_z > 0
	&& (coord[f->i][1] = y_z))
		coord[f->i++][0] = 0;
	if (x_X <= f->map->size_x && x_X > 0
	&& ((coord[f->i][0] = x_X)))
		coord[f->i++][1] = (float)f->map->size_y;
	if (y_Y <= f->map->size_y && y_Y > 0
	&& (coord[f->i][1] = y_Y))
		coord[f->i][0] = (float)f->map->size_x;
	dprintf(fd, "AIM_ONE : %f %f\nAIM_TWO : %f %f\n",
	coord[0][0], coord[0][1], coord[1][0], coord[1][1]);
}

static void	get_aim(t_filler *f)
{
	t_vec	*a;
	t_vec	*b;
	t_vec	*mid;
	t_vec	*vec;

	int fd = open("res", O_WRONLY | O_APPEND);
	a = ft_vecnew(0, 0);
	b = ft_vecnew(0, 0);
	get_mark(f, f->me->mark, &a->x, &a->y);
	get_mark(f, f->op->mark, &b->x, &b->y);
	if (a->y > b->y)
		ft_swapvec(a, b);
	dprintf(fd, "F AT: %.1f %.1f\n", a->x, a->y);
	dprintf(fd, "E AT: %.1f %.1f\n", b->x, b->y);
	if (a->y == b->y)
	{
		f->me->aim_one[0] = (b->y - a->y) / 2;
		f->me->aim_one[1] = 0;
		f->me->aim_two[0] = (b->y - a->y) / 2;
		f->me->aim_two[1] = f->map->size_y;
		return ;
	}
	dprintf(fd, "With : a(%.1f, %.1f) and b(%.1f, %.1f)\n", a->x, a->y, b->x, b->y);
	mid = ft_getmidcoor(a, b);
	dprintf(fd, "MID is : (%.1f, %.1f)\n", mid->x, mid->y);
	vec = ft_vecnew(mid->x - b->x, mid->y - b->y);
	dprintf(fd, "VEC is : (%.1f, %.1f)\n", vec->x, vec->y);
	vec = ft_get_perpendicular_vec(vec, TRUE);
	dprintf(fd, "PVEC is : (%.1f, %.1f)\n", vec->x, vec->y);
	res_aim(f, vec, mid);
}


void		play(t_filler *f)
{
	if (!f->round)
		get_aim(f);
	// ft_printf("%d %d\n", f->me->center_x, f->me->center_y);
}
