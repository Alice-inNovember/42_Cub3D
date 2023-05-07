#include "../../incs/data.h"
#include "../../incs/player_controll.h"

void	move_control(t_data *data)
{
	if (data->control.a == 1)
		key_player_move(KEY_A, data);
	if (data->control.d == 1)
		key_player_move(KEY_D, data);
	if (data->control.w == 1)
		key_player_move(KEY_W, data);
	if (data->control.s == 1)
		key_player_move(KEY_S, data);
	if (data->control.left == 1)
		key_player_rotate(KEY_LEFT, data);
	if (data->control.right == 1)
		key_player_rotate(KEY_RIGHT, data);
}

void	key_player_move(int keycode, t_data *data)
{
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		write(1, "UP\n", 3);
		up_down(data, 1 ,1);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		write(1, "DOWN\n", 6);
		up_down(data, -1, -1);
	}
	else if (keycode == KEY_D)
	{
		write(1, "RIGHT\n", 6);
		left_right(data, 1, 1);
	}
	else if (keycode == KEY_A)
	{
		write(1, "LEFT\n", 5);
		left_right(data, -1, -1);
	}
}

void	left_right(t_data *data, int x, int y)
{
	double		speed;
	double		delta_x;
	double		delta_y;

	speed = 0.005 * data->control.shift;
	delta_x = data->player->pos_x + x * data->player->plane_x * speed;
	delta_y = data->player->pos_y + y * data->player->plane_y * speed;
	if (data->map->map[(int)(delta_x)][(int)(data->player->pos_y)] == '0')
		data->player->pos_x = delta_x;
	if (data->map->map[(int)(data->player->pos_x)][(int)(delta_y)] == '0')
		data->player->pos_y = delta_y;
}

void	up_down(t_data *data, int x, int y)
{
	double		speed;
	double		delta_x;
	double		delta_y;

	speed = 0.005 * data->control.shift;
	delta_x = data->player->pos_x + x * data->player->dir_x * speed;
	delta_y = data->player->pos_y + y * data->player->dir_y * speed;
	if (data->map->map[(int)(delta_x)][(int)(data->player->pos_y)] == '0')
	{
		if(data->map->map[(int)(delta_x + 0.1)][(int)(data->player->pos_y)] != '1' \
		&& data->map->map[(int)(delta_x - 0.1)][(int)(data->player->pos_y)] != '1')
			data->player->pos_x = delta_x;
	}
		
	if (data->map->map[(int)(data->player->pos_x)][(int)(delta_y)] == '0')
	{
		if(data->map->map[(int)(data->player->pos_x)][(int)(delta_y + 0.1)] != '1' \
		&& data->map->map[(int)(data->player->pos_x)][(int)(delta_y - 0.1)] != '1')
			data->player->pos_y = delta_y;	
	}
}
