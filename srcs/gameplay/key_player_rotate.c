#include "../../incs/data.h"
#include "../../incs/player_controll.h"
#include <math.h>

void	key_player_rotate(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT)
	{
		write(1, "<-\n", 4);
		player_rotate(data, 10);
	}
	if (keycode == KEY_RIGHT)
	{
		write(1, "->\n", 4);
		player_rotate(data, -10);
	}
}

void	player_rotate(t_data *data, int speed)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = 0.001 * speed;
	old_dir_x = data->player->dir_x;
	old_plane_x = data->player->plane_x;
	data->player->dir_x = data->player->dir_x * cos(angle) - \
	data->player->dir_y * sin(angle);
	data->player->dir_y = old_dir_x * sin(angle) + \
	data->player->dir_y * cos(angle);
	data->player->plane_x = data->player->plane_x * cos(angle) - \
	data->player->plane_y * sin(angle);
	data->player->plane_y = old_plane_x * sin(angle) + \
	data->player->plane_y * cos(angle);
}
