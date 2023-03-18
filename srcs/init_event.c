/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:33:40 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/18 15:47:16 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libs/MLX/mlx.h"
#include "../incs/data.h"
#include "../incs/renderer.h"

int	red_button_hook(t_data *data)
{
	exit(EXIT_SUCCESS);
	(void)data;
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	write(1, "input\n", 6);
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	(void)data;
	return (0);
}

void	init_event(t_data *data)
{
	mlx_hook(data->libx->mlx_win, ON_DESTROY, 0, red_button_hook, &data);
	mlx_key_hook(data->libx->mlx_win, key_hook, &data);
	mlx_loop_hook(data->libx->mlx_win, renderer, &data);
}
