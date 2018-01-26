/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 18:27:20 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	set_f(t_filler *f)
{
	char	*line;
	size_t	i;
	t_map	*m;

	i = 0;
	m = ft_memalloc(sizeof(m));
	get_next_line(0, &line);
	f->me->player = ft_atoi(line + 10);
	free(line);
	f->me->mark = (f->me->player == P1) ? "oO" : "xX";
	f->me->aim_left = AIM;
	f->me->aim_right = AIM;
	f->round = 0;
	f->map = m;
}

void	set_env(t_filler *f)
{
	t_champ		champ;

	ft_bzero(f, sizeof(f));
	ft_bzero(&champ, sizeof(champ));
	f->me = &champ;
	set_f(f);
}

