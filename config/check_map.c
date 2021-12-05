/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutgercappendijk <rutgercappendijk@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:29:50 by rcappend          #+#    #+#             */
/*   Updated: 2021/09/29 08:49:45 by rutgercappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/*
** Map is only valid if all the floors and sprites are walled off.
** This code checks if no floor is encountered before a wall.
** As this would mean the map is invalid.
** Flag correct inverts whenever it encounters a wall next to an open space.
** If correct is still FALSE at the end of a line this means something is not
** walled off properly.
*/

static int	compare(t_bool *correct, const char current, const char next)
{
	if (ft_strchr(" 012NESW", current) == NULL)
		return (EXIT_FAILURE);
	if (current == FLOOR && *correct == TRUE)
		return (EXIT_FAILURE);
	if ((current == WALL && next == OPEN) || \
		(current == OPEN && next == WALL))
		*correct = !*correct;
	if (current == OPEN && *correct == FALSE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_hor(t_map map)
{
	t_bool	correct;
	int		x;

	correct = TRUE;
	while (map.height > 0)
	{
		x = map.width;
		while (x >= 0)
		{
			if (compare(&correct, xy_to_map(x, map.height, map), \
				xy_to_map(x + 1, map.height, map)) == EXIT_FAILURE)
				exit_error("Map invalid");
			x--;
		}
		if (correct == FALSE)
			exit_error("Map invalid");
		map.height--;
	}
	return (EXIT_SUCCESS);
}

static int	check_vert(t_map map)
{
	t_bool	correct;
	int		y;

	correct = TRUE;
	while (map.width > 0)
	{
		y = map.height;
		while (y >= 0)
		{
			if (compare(&correct, xy_to_map(map.width, y, map), \
				xy_to_map(map.width, y + 1, map)) == EXIT_FAILURE)
				exit_error("Map invalid");
			y--;
		}
		if (correct == FALSE)
			exit_error("Map invalid");
		map.width--;
	}
	return (EXIT_SUCCESS);
}

void	check_map(const t_map map)
{
	check_hor(map);
	check_vert(map);
}
