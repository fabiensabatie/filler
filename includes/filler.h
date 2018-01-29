/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/28 20:31:22 by fsabatie         ###   ########.fr       */
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
	char		mark;
	size_t		op_last_x;
	size_t		op_last_y;
	size_t		center_x;
	size_t		center_y;
	t_dir		last_dir;
	t_dir		avg_dir;
}				t_op;

typedef struct	s_champ
{
	t_player	player;
	char		mark;
	float		aim_one[2];
	float		aim_two[2];
	float		center_x;
	float		center_y;
}				t_champ;

typedef struct	s_filler
{
	t_champ		*me;
	t_op		*op;
	t_piece		*p;
	t_map		*map;
	t_map		*pr_map;
	size_t		round;
	size_t		i;
}				t_filler;

void	set_env(t_filler *f);
void	get_map(t_filler *f);
void	get_piece(t_filler *f);
void	play(t_filler *f);

#endif
