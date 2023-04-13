#include "../../incs/input_data.h"

void	input_data(t_data *data)
{
	input_player(data->map_obj, data->player);
	input_img(data->input, data->texture, data->libx);
}
