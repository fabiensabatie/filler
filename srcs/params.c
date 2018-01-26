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

void	set_param(t_filler *f)
{
	(void)f;
	char *line;

	get_next_line(0, &line);
	f->me->player = (ft_strstr(line, "p1")) ? P1 : P2;
	f->me->aim_left = AIM;
	f->me->aim_right = AIM;
	f->map = NULL;
	f->round = 0;
	free(line);
}

t_filler	*set_env(void)
{
	t_champ	*me;
	t_filler *f;

	P_ALLOC(me, t_champ*, sizeof(me));
	P_ALLOC(f, t_filler*, sizeof(f));
	f->me = me;
	set_param(f);
	return (f);
}