/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:48:15 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/25 19:07:21 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libs/MLX/mlx.h"
#include "../incs/data.h"
#include "../incs/util.h"
#include "../incs/init.h"
#include "../incs/map_vaildity.h"

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
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	init_data(&data, argv[1]);
	// map_vaild
	// input_data
	test_input(&data);
	init_event(&data);
	mlx_loop(data.libx->mlx);
}
