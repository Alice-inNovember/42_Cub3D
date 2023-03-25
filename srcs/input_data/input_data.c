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
