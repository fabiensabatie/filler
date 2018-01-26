/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 19:14:30 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			main(void)
{
	t_filler *f;

	f = set_env();
	while (!f->round)
	{
		get_map(f);
		f->i = 0;
		while (f->i < f->map->size_y)
			ft_printf("%s\n", f->map->grid[f->i++]);
		get_piece(f);
		// f->i = 0;
		// while (f->i < f->p->size_y)
		// 	ft_printf("%s\n", f->p->shape[f->i++]);
		f->round++;
	}
}
