/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:56:34 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 14:29:28 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"
#include "../../incs/util.h"
#include "../../incs/init.h"
#include "../../incs/map_vaildity.h"

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
