/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 16:53:58 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/03 14:07:32 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void	conf_init(t_mlx *win, t_textures *text, \
							t_player *player, t_map *map)
{
	win->res_x = -1;
	win->res_y = -1;
	text->no_text.path = NULL;
	text->ea_text.path = NULL;
	text->so_text.path = NULL;
	text->we_text.path = NULL;
	text->spr_text.path = NULL;
	text->c_col = -1;
	text->f_col = -1;
	map->map = NULL;
	map->sprites = NULL;
	map->width = 0;
	map->height = 0;
	player->x = -1;
	player->dir_x = -2;
}

/*
** this functions parses over the file line by line
** sends first 8 lines to be saved in the conf struct
** next lines are sent to be saved in the map
*/

static int	read_conf_line(char *buff, t_game *game, int *conf_n)
{
	char		*line;

	line = ft_strtrim(buff, " \t\v\f\r");
	if (!line)
		exit_error("Malloc failure");
	if (*line != '\0')
	{
		if (save_config(line, game, &game->textures, conf_n) \
			== EXIT_FAILURE)
			exit_error("Error reading file");
	}
	free(line);
	return (EXIT_SUCCESS);
}

static void	parse_file(const int fd, t_game *game)
{
	char	*buff;
	int		start;
	int		conf_n;

	buff = NULL;
	start = 1;
	conf_n = 0;
	while (start > 0)
	{
		start = get_next_line(fd, &buff);
		if (start < 0)
			exit_error("Error reading file");
		if (conf_n <= 8)
			read_conf_line(buff, game, &conf_n);
		if (conf_n == 9)
			save_map(buff, &game->map, &conf_n);
		free(buff);
	}
}

static int	read_extension(const char *file_path)
{
	int	len;

	len = ft_strlen(file_path);
	if (ft_strncmp(file_path + len - 4, ".cub", 4))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	read_file(const char *file_path, t_game *game)
{
	int		fd;

	if (read_extension(file_path) != EXIT_SUCCESS)
		exit_error("Incorrect file type");
	fd = open(file_path, O_RDONLY);
	if (!fd)
		exit_error("Error opening file");
	conf_init(&game->win, &game->textures, \
				&game->player, &game->map);
	parse_file(fd, game);
	close(fd);
	make_grid(&game->map);
	check_map(game->map);
	check_start_pos(game->map, &game->player);
}
