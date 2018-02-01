/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/01 13:11:18 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	set_env(t_filler *f)
{
	char *line;

	get_next_line(0, &line);
	f->me->player = (line[10] == '1') ? P1 : P2;
	f->me->mark = (f->me->player == P1) ? 'O' : 'X';
	f->op->mark = (f->me->mark == 'X') ? 'O' : 'X';
	f->round = 0;
	free(line);
}
