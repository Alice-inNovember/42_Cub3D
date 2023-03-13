#include "../incs/data.h"
#include "../incs/map_vaildity.h"

int	map_vaildity(t_map *map_data, t_map_obj *map_obj)
{
	int		y;
	int		x;

	map_obj_init(map_obj);
	y = 0;
	while (y < map_data->ysize - 1)
	{
		x = 0;
		while (x < map_data->xsize)
		{
			insert_map_obj(map_obj, map_data->map[y][x]);
			if (check_outline_point(map_data, y, x) == 1)
				return (1);
			if (check_four_point(map_data, y, x) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	map_obj_init(t_map_obj *map_obj)
{
	map_obj->player = 0;
}

void	insert_map_obj(t_map_obj *map, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		map->player++;
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
	if (y > 0 && map_data->map[y - 1][x] != '1'
		&& map_data->map[y - 1][x] != ' ')
		return (1);
	if (y < map_data->ysize - 2 && map_data->map[y + 1][x] != '1'
		&& map_data->map[y + 1][x] == ' ')
		return (1);
	if (x > 0 && map_data->map[y][x - 1] != '1'
		&& map_data->map[y][x - 1] != ' ')
		return (1);
	if (x < map_data->xsize - 1 && map_data->map[y][x + 1] != '1'
		&& map_data->map[y][x + 1] != ' ')
		return (1);
	return (0);
}