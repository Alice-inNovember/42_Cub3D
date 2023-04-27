#include "../../incs/input_data.h"
#include "../../incs/draw_game_img.h"

static	void	temporary_function(t_texture *tex)
{
	tex->ceiling = 0x00003333;
	tex->floor = 0x00FFFFCC;
}

void	make_background(t_texture *tex, t_libx *mlx)
{
	temporary_function(tex);
	tex->background->img = mlx_new_image(mlx->mlx, G_W, G_H);
	tex->background->addr = \
	mlx_get_data_addr(tex->background->img, &tex->background->bits_per_pixel, \
	&tex->background->line_length, &tex->background->endian);
	draw_ceiling(tex->background, tex->ceiling);
	draw_floor(tex->background, tex->floor);
}

void	draw_ceiling(t_image *game_img, t_rgb ceiling)
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