/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/16 11:10:29 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

inline void	set_env(t_filler *f)
{
	char *line;

	get_next_line(0, &line);
	f->me->player = (line[10] == '1') ? P1 : P2;
	f->me->mark = (f->me->player == P1) ? 'O' : 'X';
	f->op->mark = (f->me->mark == 'X') ? 'O' : 'X';
	f->round = 0;
	free(line);
}

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
	while (1)
	{
		get_map(&f);
		get_piece(&f);
		if (!find_fit(&f) && ft_printf("0 0\n"))
			break ;
		f.round++;
	}
	return (0);
}
