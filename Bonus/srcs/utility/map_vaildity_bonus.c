/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vaildity_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:02:22 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:16:25 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data_bonus.h"
#include "../../incs/map_vaildity_bonus.h"
#include "../../incs/util_bonus.h"

int	map_vaildity(t_map *map_data, t_map_obj *map_obj)
{
	int		y;
	int		x;

	y = 0;
	while (y < map_data->ysize)
	{
		x = 0;
		while (x < map_data->xsize)
		{
			insert_map_obj(map_obj, map_data->map[y][x], x, y);
			if (check_outline_point(map_data, y, x) == 1)
				return (1);
			if (check_four_point(map_data, y, x) == 1)
				return (1);
			if (check_door_ok(map_data, y, x) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	insert_map_obj(t_map_obj *map, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		map->player++;
		map->c = c;
		if (map->player > 1)
			err_exit(E_PLAYERCNT);
		map->player_pos[0] = y;
		map->player_pos[1] = x;
	}
}

int	check_outline_point(t_map *map_data, int y, int x)
{
	if (y != map_data->ysize - 1 && x != map_data->xsize - 1
		&& y != 0 && x != 0)
		return (0);
	if (map_data->map[y][x] != '1' && map_data->map[y][x] != ' ')
		return (1);
	return (0);
}

int	check_four_point(t_map *map_data, int y, int x)
{
	if (map_data->map[y][x] != ' ')
		return (0);
	if (y > 0 && map_data->map[y - 1][x] != '1' && \
		map_data->map[y - 1][x] != 'M' \
		&& map_data->map[y - 1][x] != ' ')
		return (1);
	if (y < map_data->ysize - 2 && map_data->map[y + 1][x] != '1' \
		&& map_data->map[y + 1][x] != 'M' \
		&& map_data->map[y + 1][x] != ' ')
		return (1);
	if (x > 0 && map_data->map[y][x - 1] != '1' && \
		map_data->map[y][x - 1] != 'M' \
		&& map_data->map[y][x - 1] != ' ')
		return (1);
	if (x < map_data->xsize - 1 && map_data->map[y][x + 1] != '1' && \
		map_data->map[y][x + 1] != 'M' \
		&& map_data->map[y][x + 1] != ' ')
		return (1);
	return (0);
}

int	check_door_ok(t_map *map_data, int y, int x)
{
	if (map_data->map[y][x] != 'M')
		return (0);
	if (map_data->map[y + 1][x] == '1' && map_data->map[y - 1][x] == '1')
		return (0);
	if (map_data->map[y][x + 1] == '1' && map_data->map[y][x - 1] == '1')
		return (0);
	return (1);
}
