/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 19:19:42 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_piece	*init_piece(t_filler *f)
{
	t_piece	*p;
	char *l;

	P_ALLOC(p, t_piece*, sizeof(p));
	get_next_line(0, &l);
	p->size_y = ft_atoi(l + 6);
	f->i = 0;
	while (ft_isdigit(*(l + 6 + f->i)))
		f->i++;
	p->size_x = ft_atoi(l + 6 + f->i);
	free(l);
	P_ALLOC(p->shape, char**, (sizeof(char*) * (p->size_y + 1)));
	f->i = 0;
	ft_printf("Done\n");
	while (f->i < p->size_y)
		P_ALLOC(p->shape[f->i++], char*, (sizeof(char) * (p->size_x + 1)));
	ft_printf("2Done");
	return (p);
}

void	get_piece(t_filler *f)
{
	// char	*l;

	if (!f->round)
		(void)f;
	f->p = init_piece(f);


	// i = 0;
	// while (i < f->p->size_y)
	// {
	// 	f->i = 0;
	// 	get_next_line(0, &l);
	// 	ft_strcpy(f->p->shape[i++], l);
	// 	free(l);
	// }
}