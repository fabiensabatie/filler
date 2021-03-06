/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:29:27 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/08 15:16:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"
#define _MAP "./visualizer/ressources/assets/map.xpm"
#define _MAP_SMALL "./visualizer/ressources/assets/map_small.xpm"
#define _PLAY "./visualizer/ressources/assets/PlayLarge.xpm"
#define _PLAY_SMALL "./visualizer/ressources/assets/PlaySmall.xpm"
#define _PAUSE "./visualizer/ressources/assets/PauseLarge.xpm"
#define _PAUSE_SMALL "./visualizer/ressources/assets/PauseSmall.xpm"
#define _TITLE "Filler visualizer, by nfinkel and fsabatie"
#define BUFF_SIZE 16

static t_mlx				*output_grid(t_mlx *mlx)
{
	char		*line;
	size_t		nb;
	size_t		width;

	if (!mlx)
		ZOMG;
	EPICFAILZ(get_next_line(STDIN_FILENO, &line), NULL);
	mlx->MAP_Y = ft_atoi(line + 8);
	mlx->MAP_X = ft_atoi(line + ft_intlen(mlx->MAP_Y) + 9);
	if (mlx->MAP_X > 100 || mlx->MAP_Y > 100)
		ft_fatal("map size isn't supported by visualizer");
	ft_strdel(&line);
	nb = MAX(mlx->MAP_X, mlx->MAP_Y);
	width = WIN_X / 2;
	mlx->SQRLEN = (width - (nb - 1)) / nb;
	mlx->PAD_X = (width - ((mlx->MAP_X * mlx->SQRLEN) + mlx->MAP_X - 1)) / 2;
	mlx->PAD_Y = (width - ((mlx->MAP_Y * mlx->SQRLEN) + mlx->MAP_Y - 1)) / 2;
	EPICFAILZ(color_squares(mlx), NULL);
	GIMME(mlx);
}

static inline t_mlx			*display_players(t_mlx *mlx, const char *p1n,
							const char *p2n)
{
	int		p1x;
	int		p2x;
	int		py;

	p1x = (WIN_X == 1920 ? 120 : 90);
	p2x = (WIN_X == 1920 ? 1560 : 980);
	py = (WIN_X == 1920 ? 225 : 140);
	put_swstr(mlx, p1n, p1x, py);
	put_swstr(mlx, p2n, p2x, py);
	put_swstr(mlx, "0", _P1SCORE, _PYSCORE);
	put_swstr(mlx, "0", _P2SCORE, _PYSCORE);
	GIMME(mlx);
}

static t_mlx				*do_players(t_mlx *mlx)
{
	char		p1n[BUFF_SIZE];
	char		p2n[BUFF_SIZE];
	char		*line;
	int			k;

	k = 10;
	while (--k)
	{
		EPICFAILZ(get_next_line(STDIN_FILENO, &line), NULL);
		if (line[0] == '$' && line[10] == '1')
			ft_snprintf(p1n, BUFF_SIZE, "%s", ft_strrchr(line, '/') + 1);
		else if (line[0] == '$' && line[10] == '2')
			ft_snprintf(p2n, BUFF_SIZE, "%s", ft_strrchr(line, '/') + 1);
		else if (line[0] == '.' || ft_strequ(line, "error:"))
			errhdl(mlx, line);
		else if (line[0] != 'l' && line[0] != '#' && line[0] != 'P')
			ft_fatal("wrong input");
		ft_strdel(&line);
	}
	if ((line = ft_strchr(&p1n[0], '.')))
		*line = '\0';
	if ((line = ft_strchr(&p2n[0], '.')))
		*line = '\0';
	EPICFAILZ(do_font(mlx), NULL);
	GIMME(display_players(mlx, p1n, p2n));
}

static inline void			display_board(t_mlx *mlx, int x, int y)
{
	char		*path;
	void		*xpm;

	WIN_X = x;
	WIN_Y = y;
	path = (WIN_X == 1920 ? _MAP : _MAP_SMALL);
	if (!(xpm = mlx_xpm_file_to_image(_MLX, path, &x, &y)))
		ft_fatal("could not locate xpm file, restart from filler directory");
	mlx_put_image_to_window(_MLX, _WIN, xpm, 0, 0);
	if (!output_grid(do_players(mlx)))
		ft_fatal("allocation failed");
	mlx_destroy_image(_MLX, xpm);
	path = (WIN_X == 1920 ? _PLAY : _PLAY_SMALL);
	mlx->bplay = mlx_xpm_file_to_image(_MLX, path, &x, &y);
	path = (WIN_X == 1920 ? _PAUSE : _PAUSE_SMALL);
	mlx->bpause = mlx_xpm_file_to_image(_MLX, path, &x, &y);
}

int							main(int argc, const char *argv[])
{
	int			x;
	int			y;
	t_mlx		*mlx;

	if (argc > 1 && (ft_strequ(argv[1], "--low") || ft_strequ(argv[1], "-l")))
		x = 1200;
	else if (argc > 1)
		GIMME(ft_printf("Usage: <filler command> | ./visualizer/visualizer "\
			"[-l]\n-l  --low: use 1200x675 resolution\n"));
	else
		x = 1920;
	y = (x == 1920 ? 1080 : 675);
	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx)))
	|| !(_MLX = mlx_init())
	|| (!(_WIN = mlx_new_window(_MLX, x, y, _TITLE))))
		ft_fatal("allocation failed");
	display_board(mlx, x, y);
	mlx_put_image_to_window(_MLX, _WIN, mlx->bpause, 0, 0);
	mlx_mouse_hook(_WIN, &hook_mouse, mlx);
	mlx_key_hook(_WIN, &hook_key, mlx);
	mlx_loop_hook(_MLX, &hook_loop, mlx);
	GIMME(mlx_loop(_MLX));
}
