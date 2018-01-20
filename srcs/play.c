/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/19 17:59:41 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <unistd.h>

void	read_map(t_filler *f)
{
	(void)f;
	char *str = "1 8\n";
	write(1, str, ft_strlen(str));
}

void	play(t_filler *f)
{
	char *line;

	while (get_next_line(0, &line))
		read_map(f);
}