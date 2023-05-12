/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_wall_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:24:15 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 14:24:29 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data.h"
#include <stdio.h>
#include <stdlib.h>

static void	temporary_function(t_input *input)
{
	free(input->ea_png);
	free(input->no_png);
	free(input->so_png);
	free(input->we_png);
	input->ea_png = "imgs/E_wall.xpm";
	input->no_png = "imgs/N_wall.xpm";
	input->so_png = "imgs/S_wall.xpm";
	input->we_png = "imgs/W_wall.xpm";
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
}
