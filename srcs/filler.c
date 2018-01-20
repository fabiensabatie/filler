/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/19 17:59:41 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	set_f(t_filler *f)
{
	char	*line;

	get_next_line(0, &line);
	f->me->player = ft_atoi(line + 10);
	free(line);
	get_next_line(0, &line);
	f->map_x = ft_atoi(line + 8);
	f->map_y = ft_atoi(line + 10);
	f->me->mark = (f->me->player == P1) ? "oO" : "xX";
	free(line);
}

int			main(void)
{
	t_filler	f;
	t_champ		champ;

	ft_bzero(&f, sizeof(f));
	ft_bzero(&champ, sizeof(champ));
	f.me = &champ;
	set_f(&f);
	while (1)
		play(&f);
}
