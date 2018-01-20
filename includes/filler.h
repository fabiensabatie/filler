/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/19 18:19:02 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <stdlib.h>
# define MARK 0;
# define L_MARK 1;

typedef enum	e_player
{
	P1 = 1,
	P2 = 2
}				t_player;

typedef enum	e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}				t_dir;

typedef struct	s_piece
{
	size_t		piece_x;
	size_t		piece_y;
}				t_piece;

typedef struct	s_opponent
{
	size_t		op_last_x;
	size_t		op_last_y;
	t_dir		last_dir;
	t_dir		avg_dir;
}				t_op;

typedef struct	s_champ
{
	t_player	player;
	char		*mark;
}				t_champ;

typedef struct	s_filler
{
	t_champ		*me;
	t_op		*op;
	t_piece		*cur_piece;
	size_t		map_x;
	size_t		map_y;
	float		aim_left;
	float		aim_right;
	float		center_x;
	float		center_y;
}				t_filler;

void	play(t_filler *f);

#endif
