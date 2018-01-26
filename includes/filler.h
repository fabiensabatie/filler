/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 17:54:43 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# define MARK 0
# define L_MARK 1
# define AIM (0.66)

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

typedef struct	s_map
{
	size_t		size_x;
	size_t		size_y;
	char		**grid;
}				t_map;


typedef struct	s_piece
{
	size_t		size_x;
	size_t		size_y;
	char		**shape;
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
	char		mark;
	float		aim_left;
	float		aim_right;
	float		center_x;
	float		center_y;
}				t_champ;

typedef struct	s_filler
{
	t_champ		*me;
	t_op		*op;
	t_piece		*p;
	t_map		*map;
	size_t		round;
	size_t		i;
	char		*gnl_start;
}				t_filler;

t_filler	*set_env(void);
void		get_map(t_filler *f);
void		get_piece(t_filler *f);

#endif
