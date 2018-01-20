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

typedef enum	e_dir
{
	LEFT,
	RIGHT
}				e_dir;

typedef struct	s_opponent
{
	size_t		op_last_x;
	size_t		op_last_y;
	e_dir		last_dir;
	e_dir		avg_dir;
}				t_op;

typedef struct	s_filler
{
	size_t		map_x;
	size_t		map_y;
	float		aim_left;
	float		aim_right;
	float		center_x;
	float		center_y;
}				t_filler;

typedef struct	s_piece
{
	size_t		piece_x;
	size_t		piece_y;
}				t_piece;


#endif
