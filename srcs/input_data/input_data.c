#include "../../incs/input_data.h"

void	input_data(t_data *data)
{
	input_player(data->map_obj, data->player);
	data->map->map[data->map_obj->player_pos[0]][data->map_obj->player_pos[1]] = '0';
	input_img(data->input, data->texture, data->libx);
}
