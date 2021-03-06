/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:23:16 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/08 15:20:13 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/mlx_keys.h"
# include "../ressources/mlx/mlx.h"

# define WIN_X mlx->win.win_x
# define WIN_Y mlx->win.win_y
# define _ADJUST(x) ((x) * (mlx->SQRLEN + 1))
# define _PADX WIN_X / 4 + mlx->PAD_X
# define _PADY mlx->PAD_Y
# define _MLX mlx->mlx
# define _WIN mlx->win_ptr
# define _P1C 0x2e99e3
# define _P2C 0xb71345
# define _P1SCORE (WIN_X == 1920 ? 155 : 95)
# define _P2SCORE (WIN_X == 1920 ? 1555 : 990)
# define _PYSCORE (WIN_X == 1920 ? 820 : 510)

typedef struct		s_mlx
{
	bool			mouse;
	bool			play;
	int				p1score;
	int				p2score;
	struct			s_sqr
	{
		int			bppx;
		int			sl;
		int			endian;
		int			sqrlen;
	}				sqr;
	struct			s_window
	{
		short		win_x;
		short		win_y;
		uint8_t		map_x;
		uint8_t		map_y;
		uint8_t		pad_x;
		uint8_t		pad_y;
	}				win;
	void			*bclean;
	void			*bg;
	void			*bplay;
	void			*bpause;
	void			*bsqr;
	void			*clean1;
	void			*clean2;
	void			*mlx;
	void			*sqrp1;
	void			*sqrp2;
	void			*win_ptr;
	void			**font;
}					t_mlx;

# define BPPX sqr.bppx
# define ENDIAN sqr.endian
# define SL sqr.sl
# define SQRLEN sqr.sqrlen
# define MAP_X win.map_x
# define MAP_Y win.map_y
# define PAD_X win.pad_x
# define PAD_Y win.pad_y

int					color_squares(t_mlx *mlx);
int					do_font(t_mlx *mlx);
int					do_map(t_mlx *mlx, int *p1score, int *p2score);
void				errhdl(t_mlx *mlx, char *line);
int					hook_key(int key, t_mlx *mlx);
int					hook_mouse(int button, int x, int y, t_mlx *mlx);
int					hook_loop(t_mlx *mlx);
int					init_map(const t_mlx *mlx);
const t_mlx			*put_swstr(const t_mlx *mlx, const char *str, int x,
					const int y);

#endif
