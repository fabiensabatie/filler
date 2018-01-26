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

void	set_env(t_filler *f)
{
	char *line;

	get_next_line(0, &line);
	f->me->player = (ft_strstr(line, "p1")) ? P1 : P2;
	f->me->aim_left = AIM;
	f->me->aim_right = AIM;
	f->round = 0;
	free(line);
}
