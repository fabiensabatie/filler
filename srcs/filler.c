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
	t_filler	f;
	t_champ		me;
	t_op		op;
	t_map		m;
	t_piece		p;

	ft_bzero(&f, sizeof(f));
	ft_bzero(&me, sizeof(me));
	ft_bzero(&op, sizeof(op));
	ft_bzero(&m, sizeof(m));
	ft_bzero(&p, sizeof(p));
	f.me = &me;
	f.op = &op;
	f.map = &m;
	f.p = &p;
	set_env(&f);
	while (!f.round)
	{
		get_map(&f);
		get_piece(&f);
		play(&f);
		f.round++;
	}
}
