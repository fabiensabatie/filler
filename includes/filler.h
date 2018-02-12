/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/04 16:07:50 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# define MARK 0
# define L_MARK 1
# define FMX f->map->size_x
# define FMY f->map->size_y
# define FMG f->map->grid
# define FPX f->p->size_x
# define FPY f->p->size_y
# define FPS f->p->shape
# define FPDX f->p->decal_x
# define FPDY f->p->decal_y
# define FPW f->p->wildcars
# define FPW f->p->wildcars
# define FMEM f->me->mark
# define FOPM f->op->mark
# define AIM f->me->aim

typedef enum	e_player
{
	P1 = 1,
	P2 = 2
}				t_player;

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
	int			decal_x;
	int			decal_y;
	size_t		wildcars;
	char		**shape;
}				t_piece;

typedef struct	s_opponent
{
	char		mark;
}				t_op;

typedef struct	s_champ
{
	t_player	player;
	char		mark;
	float		aim[3][2];
}				t_champ;

typedef struct	s_filler
{
	t_champ		*me;
	t_op		*op;
	t_piece		*p;
	t_map		*map;
	size_t		round;
	size_t		i;
	int			fits[1000000][2];
	int			bx;
	int			by;
}				t_filler;

void			set_env(t_filler *f);
void			get_map(t_filler *f);
void			get_piece(t_filler *f);
int				find_fit(t_filler *f);
int				p_fits(t_filler *f, int x, int y);

#endif
