#include "data.h"

void	*draw_game_img(t_image game_img, t_data *data)
{
	draw_ceiling(game_img, data->texture->ceiling);
	draw_floor(game_img, data->texture->floor);
	draw_other(game_img, data);
	return (game_img.img);
}
