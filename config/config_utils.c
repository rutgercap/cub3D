/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 16:48:38 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/03 13:00:55 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	xy_to_map(const int x, const int y, const t_map map)
{
	if (x < 1 || x > map.width || y < 1 || y > map.height)
		return (OPEN);
	return (map.map[y - 1][x - 1]);
}
