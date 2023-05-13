/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:15:45 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/13 23:56:45 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"
#include "../../incs/util.h"
#include "../../incs/draw_game_img.h"

void	draw_background(t_image *wall_img, t_texture *tex)
{
	draw_ceiling(wall_img, tex->ceiling);
	draw_floor(wall_img, tex->floor);
}

void	draw_ceiling(t_image *game_img, t_rgb ceiling)
{
	int	x;
	int	y;
	int	max;

	y = 0;
	max = G_H / 2;
	printf("ceiling %d\t", ceiling);
	while (y < max)
	{
		x = 0;
		while (x < G_W)
		{
			my_mlx_pixel_put(game_img, x, y, ceiling);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_image *game_img, t_rgb floor)
{
	int	x;
	int	y;
	int	max;

	y = G_H / 2;
	max = G_H;
	printf("floor %d\n", floor);
	while (y < max)
	{
		x = 0;
		while (x < G_W)
		{
			my_mlx_pixel_put(game_img, x, y, floor);
			x++;
		}
		y++;
	}
}
