/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:48:15 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:56:16 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libs/MLX/mlx.h"
#include "../incs/data_bonus.h"
#include "../incs/util_bonus.h"
#include "../incs/init_bonus.h"
#include "../incs/map_vaildity_bonus.h"
#include "../incs/minimap_bonus.h"
#include "../incs/input_data_bonus.h"

void	init_data(t_data *data, char *input_file)
{
	data->libx = ft_calloc(1, sizeof(t_libx));
	init_libx(data);
	data->input = ft_calloc(1, sizeof(t_input));
	init_input(data, input_file);
	data->map = ft_calloc(1, sizeof(t_map));
	init_map(data);
	data->texture = ft_calloc(1, sizeof(t_texture));
	init_texture(data);
	data->player = ft_calloc(1, sizeof(t_player));
	init_player(data);
	data->screen = ft_calloc(1, sizeof(t_image));
	init_screen(data);
	data->map_obj = ft_calloc(1, sizeof(t_map_obj));
	init_map_obj(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		err_exit(E_ARGCNT);
	init_data(&data, argv[1]);
	if (map_vaildity(data.map, data.map_obj) == 1)
		err_exit(E_MAPVALID);
	input_data(&data);
	if (minimap(data.map, &data) == 1)
		err_exit(E_MAPVALID);
	data.libx->mlx_win = mlx_new_window(\
	data.libx->mlx, 640, 480, data.libx->win_name);
	mlx_do_key_autorepeaton(data.libx->mlx);
	mlx_mouse_move(data.libx->mlx_win, G_W / 2, G_H / 2);
	init_event(&data);
	mlx_loop(data.libx->mlx);
}
