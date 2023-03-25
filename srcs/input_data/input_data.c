#include "../incs/data.h"

void	input_data(t_data *data)
{
	input_player(data->map_obj, data->player);
}

void	input_player(t_map_obj *map_obj, t_player *player)
{
	player->pos_x = map_obj->player_pos[0];
	player->pos_y = map_obj->player_pos[1];
}

void	dir_plane_input(int x, t_player *player)
{
	if (x == 0)
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (x == 1)
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (x == 2)
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = 0.66;
		player->plane_y = 0.0;
	}
	else if (x == 3)
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
}