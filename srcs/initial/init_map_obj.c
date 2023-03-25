#include "../../incs/data.h"

void	init_map_obj(t_data *data)
{
	data->map_obj->c = 0;
	data->map_obj->player = 0;
	data->map_obj->player_pos[0] = 0;
	data->map_obj->player_pos[1] = 1;
}
