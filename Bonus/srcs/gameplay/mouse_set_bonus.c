/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_set_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:19:39 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:51:46 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data_bonus.h"
#include "../../incs/util_bonus.h"
#include "../../incs/player_controll_bonus.h"

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
		if (data->mouse.mouse_speed > 1)
			data->mouse.mouse_speed -= 5;
		else
			write(1, "alreay mouse speed is min\n", 26);
	}
	else
	{
		if (data->mouse.mouse_speed < 100)
			data->mouse.mouse_speed += 5;
		else
			write(1, "alreay mouse speed is max\n", 26);
	}
}
