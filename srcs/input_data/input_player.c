#include "../incs/input_data.h"

void	input_player(t_map_obj *map_obj, t_player *player)
{
	input_pos(map_obj, player);
	input_dir_plane(map_obj->c, player);
}

void	input_pos(t_map_obj *map_obj, t_player *player)
{
	player->pos_x = (double)(map_obj->player_pos[0]);
	player->pos_y = (double)(map_obj->player_pos[1]);
}

void	input_dir_plane(int x, t_player *player)
{
	if (x == 'E')
	{
		player->dir_x = -1.0;
		player->plane_y = 0.66;
	}
	else if (x == 'W')
	{
		player->dir_x = 1.0;
		player->plane_y = -0.66;
	}
	else if (x == 'S')
	{
		player->dir_y = -1.0;
		player->plane_x = 0.66;
	}
	else if (x == 'N')
	{
		player->dir_y = 1.0;
		player->plane_x = -0.66;
	}
}
