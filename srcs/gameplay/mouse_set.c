#include "../../incs/data.h"
#include "../../incs/player_controll.h"

void	mouse_set(int keycode, t_data *data)
{
	if (keycode == 18)
		mouse_tran_control(data);
	else
		mouse_speed_control(keycode, data);
}

void	mouse_tran_control(t_data *data)
{
	data->mouse.tran_mouse *= -1;
	if (data->mouse.tran_mouse == 1)
		mlx_mouse_hide();
	else
		mlx_mouse_show();
}

void	mouse_speed_control(int keycode, t_data *data)
{
	if (keycode == 19)
	{
		if (data->mouse.mouse_speed < 100)
			data->mouse.mouse_speed += 1;
		else
			printf("alreay mouse speed is max\n");
	}
	else
	{
		if (data->mouse.mouse_speed > 1)
			data->mouse.mouse_speed -= 1;
		else
			printf("alreay mouse speed is min\n");
	}
}