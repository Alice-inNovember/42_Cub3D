/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:48:15 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/17 13:46:32 by junlee2          ###   ########seoul.kr  */
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

void	init_data(t_data *data, char *input_file)
{
	data->libx = ft_calloc(1, sizeof(t_libx));
	init_libx(data);
	data->input = ft_calloc(1, sizeof(t_input));
	init_input(data, input_file);
	data->map = ft_calloc(1, sizeof(t_map));
	init_map(data);
}

void	print_map(t_data *data, size_t i)
{
	i = 0;
	while (i < ft_strlen(data->map->map[1]) + 2)
	{
		write(1, "-", 1);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	while (data->map->map[i])
	{
		printf("|%s|\n", data->map->map[i]);
		i++;
	}
	i = 0;
	while (i < ft_strlen(data->map->map[1]) + 2)
	{
		write(1, "-", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	test_input(t_data *data)
{
	printf("%s\n", data->input->no_png);
	printf("%s\n", data->input->so_png);
	printf("%s\n", data->input->ea_png);
	printf("%s\n", data->input->we_png);
	printf("%s\n", data->input->ceiling);
	printf("%s\n", data->input->floor);
	print_map(data, 0);
	printf("map size\n");
	printf("x : %d, y : %d\n", data->map->xsize, data->map->ysize);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	init_data(&data, argv[1]);
	test_input(&data);
	mlx_loop(data.libx->mlx);
}
