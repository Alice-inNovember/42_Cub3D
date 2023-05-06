#include "../../incs/draw_game_img.h"

void	drawing_game_img(t_other_draw *draw_info, t_image *game_img, t_image img, int x)
{
	int	y;

	y = draw_info->draw_start;
	while (y < draw_info->draw_end)
	{
		draw_info->get_img_y = (int)draw_info->draw_pos & (IMG_H - 1);
		draw_info->color = \
		get_color(&img, draw_info->get_img_x, draw_info->get_img_y);
		my_mlx_pixel_put(game_img, x, y, draw_info->color);
		y++;
		draw_info->draw_pos += draw_info->step;
	}
}
