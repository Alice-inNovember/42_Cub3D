#ifndef MAP_VAILDITY_H
# define MAP_VAILDITY_H

# include "data.h"

typedef struct s_map_obj
{
	int	player;
}	t_map_obj;

int		map_vaildity(t_map *map_data, t_map_obj *map_obj);
int		check_outline_point(t_map *map_data, int y, int x);
int		check_four_point(t_map *map_data, int y, int x);
void	map_obj_init(t_map_obj *map_obj);
void	insert_map_obj(t_map_obj *map, char c);

#endif