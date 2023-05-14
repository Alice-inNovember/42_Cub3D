/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_wall_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:24:15 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/14 16:38:48 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../incs/util.h"

char	*get_wall_tex(char *path)
{
	char	**temp;

	temp = ft_split(path, ' ');
	if (arr_len(temp) != 2)
		err_exit("Error\n : Map not valid");
	if (ft_strcmp(&temp[1][ft_strlen(temp[1]) - 4], ".xpm"))
		err_exit("Error\n : .xpm img only");
	free(path);
	path = ft_strdup(temp[1]);
	free_arr(temp);
	return (path);
}

static void	temporary_function(t_input *input)
{
	input->ea_png = get_wall_tex(input->ea_png);
	input->no_png = get_wall_tex(input->no_png);
	input->so_png = get_wall_tex(input->so_png);
	input->we_png = get_wall_tex(input->we_png);
}

void	tran_mlx_img(t_input *input, t_texture *tex, t_libx *mlx)
{
	int	wid;
	int	hei;

	temporary_function(input);
	tex->wall_e->img = \
	mlx_xpm_file_to_image(mlx->mlx, input->ea_png, &wid, &hei);
	tex->wall_n->img = \
	mlx_xpm_file_to_image(mlx->mlx, input->no_png, &wid, &hei);
	tex->wall_s->img = \
	mlx_xpm_file_to_image(mlx->mlx, input->so_png, &wid, &hei);
	tex->wall_w->img = \
	mlx_xpm_file_to_image(mlx->mlx, input->we_png, &wid, &hei);
	tex->door->img = \
	mlx_xpm_file_to_image(mlx->mlx, "./imgs/door.xpm", &wid, &hei);
}

void	make_t_images(t_texture *tex)
{
	tex->wall_e->addr = \
	mlx_get_data_addr(tex->wall_e->img, &tex->wall_e->bits_per_pixel, \
					&tex->wall_e->line_length, &tex->wall_e->endian);
	tex->wall_n->addr = \
	mlx_get_data_addr(tex->wall_n->img, &tex->wall_n->bits_per_pixel, \
					&tex->wall_n->line_length, &tex->wall_n->endian);
	tex->wall_s->addr = \
	mlx_get_data_addr(tex->wall_s->img, &tex->wall_s->bits_per_pixel, \
					&tex->wall_s->line_length, &tex->wall_s->endian);
	tex->wall_w->addr = \
	mlx_get_data_addr(tex->wall_w->img, &tex->wall_w->bits_per_pixel, \
					&tex->wall_w->line_length, &tex->wall_w->endian);
	tex->door->addr = \
	mlx_get_data_addr(tex->door->img, &tex->door->bits_per_pixel, \
					&tex->door->line_length, &tex->door->endian);
}
