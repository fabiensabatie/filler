/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/01 13:20:06 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

// static void	get_mark(t_filler *f, char mark,
// float *center_x, float *center_y)
// {
// 	size_t i;
//
// 	i = 1;
// 	while (i <= f->map->size_y)
// 	{
// 		f->i = 1;
// 		while (f->i <= f->map->size_x)
// 		{
// 			if (f->map->grid[i][f->i] == mark)
// 			{
// 				*center_x = f->i;
// 				*center_y = i;
// 				return ;
// 			}
// 			f->i++;
// 		}
// 		i++;
// 	}
// }

// static void	res_aim(t_filler *f, t_vec *vec, t_vec *mid)
// {
// 	t_equa *e;
// 	t_equa res;
// 	float coord[2][2];
//
// 	e = ft_equanew(0, 0, vec->y / vec->x, 0);
// 	e->b = mid->y - e->a * mid->x;
// 	res.y = (e->a != 0) ? (0 - e->b) / e->a : -1;
// 	res.x = e->a * 0 + e->b;
// 	res.a = (e->a != 0) ? ((float)f->map->size_y - e->b) / e->a : -1;
// 	res.b = e->a * (float)f->map->size_x + e->b;
// 	f->i = 0;
// 	if (res.y <= f->map->size_x && res.y > 0
// 	&& (coord[f->i][0] = res.y))
// 		coord[f->i++][1] = 0;
// 	if (res.x <= f->map->size_y && res.x > 0
// 	&& (coord[f->i][1] = res.x))
// 		coord[f->i++][0] = 0;
// 	if (res.a <= f->map->size_x && res.a > 0
// 	&& ((coord[f->i][0] = res.a)))
// 		coord[f->i++][1] = (float)f->map->size_y;
// 	if (res.b <= f->map->size_y && res.b > 0
// 	&& (coord[f->i][1] = res.b))
// 		coord[f->i][0] = (float)f->map->size_x;
// }
//
// static int	get_coord(t_filler *f)
// {
// 	size_t x;
// 	size_t y;
//
// 	y = 0;
// 	int fd = open("res", O_WRONLY | O_APPEND);
// 	p_decal(f);
// 	while (++y < f->map->size_y)
// 	{
// 		x = 0;
// 		while (++x < f->map->size_x)
// 		{
// 			if (p_fits(f, x, y))
// 			{
// 				ft_dprintf(fd, "%ld %ld\n",
// 				x - f->p->decal_x, y - f->p->decal_y);
// 				return (ft_printf("%ld %ld\n",
// 				x - f->p->decal_x, y - f->p->decal_y));
// 			}
// 		}
// 	}
// 	return (0);
// }
//
// static void	get_aim(t_filler *f)
// {
// 	t_vec	*a;
// 	t_vec	*b;
// 	t_vec	*mid;
// 	t_vec	*vec;
//
// 	a = ft_vecnew(0, 0);
// 	b = ft_vecnew(0, 0);
// 	get_mark(f, f->me->mark, &a->x, &a->y);
// 	get_mark(f, f->op->mark, &b->x, &b->y);
// 	if (a->y > b->y)
// 		ft_swapvec(a, b);
// 	if (a->y == b->y)
// 	{
// 		f->me->aim_one[0] = (b->y - a->y) / 2;
// 		f->me->aim_one[1] = 0;
// 		f->me->aim_two[0] = (b->y - a->y) / 2;
// 		f->me->aim_two[1] = f->map->size_y;
// 		return ;
// 	}
// 	mid = ft_getmidcoor(a, b);
// 	vec = ft_vecnew(mid->x - b->x, mid->y - b->y);
// 	vec = ft_get_perpendicular_vec(vec, TRUE);
// 	res_aim(f, vec, mid);
// }


void		play(t_filler *f)
{
	// if (!f->round)
	// 	get_aim(f);
	// get_coord(f);
	
}
