/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 12:32:25 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/02 16:02:30 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	init_window(t_mlx *win)
{
	int		screen_x;
	int		screen_y;

	mlx_get_screen_size(win->mlx, &screen_x, &screen_y);
	if (win->res_x > screen_x)
		win->res_x = screen_x;
	if (win->res_y > screen_y)
		win->res_y = screen_y;
	win->win = mlx_new_window(win->mlx, win->res_x, win->res_y, "cub3d");
	if (!win->win)
		exit_error("Failed to initialise window");
}

static void	init_image(t_image *img, const t_mlx *win)
{
	img->img = mlx_new_image(win->mlx, win->res_x, win->res_y);
	if (!img->img)
		exit_error("Failed to initialise image");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, \
				& img->endian);
	if (!img->addr)
		exit_error("Failed to initialise image");
}

void	init_mlx(t_game *game)
{
	game->win.mlx = mlx_init();
	if (!game->win.mlx)
		exit_error("Failed to initialise window");
	init_window(&game->win);
	init_image(&game->img_1, &game->win);
	init_image(&game->img_2, &game->win);
}
