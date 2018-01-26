/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 15:11:28 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	get_X(t_filler *f)
{
	size_t i;

	i = 0;
	while (i < f->map->size_y)
	{
		f->i = 0;
		while (f->i < f->map->size_x)
		{
			if (f->map->grid[i][f->i] == 'X')
			{
				f->me->center_x = f->i;
				f->me->center_y = i;
				return ;
			}
			f->i++;
		}
		i++;
	}
}

void		play(t_filler *f)
{
	size_t i;

	i = 0;
	get_X(f);
	ft_printf("%d %d\n", f->me->center_y, f->me->center_x);
}