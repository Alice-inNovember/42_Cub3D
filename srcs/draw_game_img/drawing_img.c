#include "data.h"

void	draw_ceiling(t_image game_img, t_rgb ceiling)
{
	int	x;
	int	y;
	int	max;

	y = 0;
	max = G_H / 2;
	while (y < max)
	{
		x = 0;
		while (x < G_W)
		{
			my_mlx_pixel_put(&game_img, x, y, ceiling);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_image game_img, t_rgb floor)
{
	int	x;
	int	y;
	int	max;

	y = G_H / 2;
	max = G_H;
	while (y < max)
	{
		x = 0;
		while (x < G_W)
		{
			my_mlx_pixel_put(&game_img, x, y, floor);
			x++;
		}
		y++;
	}
}

void	drawing_game_img(t_other_draw *draw_info, \
		t_image game_img, t_image img, int x)
{
	int	y;

	y = draw_info->draw_start;
	while (y < draw_info->draw_end)
	{
		y++;
		draw_info->get_img_y = (int)draw_info->draw_pos & (IMG_H - 1);
		draw_info->draw_pos += draw_info->step;
		draw_info->color = \
		get_color(&img, draw_info->get_img_x, draw_info->get_img_y);
		my_mlx_pixel_put(&game_img, x, y, draw_info->color);
	}
}
