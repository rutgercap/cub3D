/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_pos.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 08:15:59 by rutgercappe   #+#    #+#                 */
/*   Updated: 2021/11/03 13:48:28 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	north_east_to_dir(t_player *player)
{
	if (player->dir_x == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.5;
		player->plane_y = 0;
	}
	else if (player->dir_x == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.5;
	}
}

void	south_west_to_dir(t_player *player)
{
	if (player->dir_x == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.5;
		player->plane_y = 0;
	}
	else if (player->dir_x == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.5;
	}
}

void	save_location(const int x, const int y, t_map map, t_player *player)
{
	if (player->dir_x != NOT_SET)
		exit_error("Double start position");
	else
	{
		player->x = x + 0.5;
		player->y = y + 0.5;
		player->dir_x = xy_to_map(x, y, map);
	}
}

void	find_start_pos(t_map map, t_player *player)
{
	int		x;
	t_bool	inside;

	while (map.height > 0)
	{
		inside = FALSE;
		x = map.width;
		while (x > 0)
		{
			if (xy_to_map(x, map.height, map) == WALL)
				inside = TRUE;
			if (xy_to_map(x, map.height, map) == OPEN)
				inside = FALSE;
			if (ft_strchr("NESW", xy_to_map(x, map.height, map)) != NULL)
			{
				if (inside == FALSE)
					exit_error("Invalid start position");
				else
					save_location(x, map.height, map, player);
			}
			x--;
		}
		map.height--;
	}
}

void	check_start_pos(t_map map, t_player *player)
{
	find_start_pos(map, player);
	if (player->dir_x == 'N' || player->dir_x == 'E')
		north_east_to_dir(player);
	else if (player->dir_x == 'S' || player->dir_x == 'W')
		south_west_to_dir(player);
	if (player->dir_x == NOT_SET)
		exit_error("No start position given");
}
