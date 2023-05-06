#include "../../incs/draw_game_img.h"

void	draw_wall_img(t_image *game_img, t_data *data)
{
	int				x;
	t_detail_info	info;
	t_other_draw	draw_info;

	x = 0;
	draw_background(data->texture->wall_img, data->texture);
	while (x < G_W)
	{
		init_info(&info);
		init_draw_init(&draw_info);
		input_need_for_raycating(data->player, &info, x);
		input_ray_step(data->player, &info);
		ray_casting(data->map, &info);
		select_img(data->player, &info);
		calc_dist_valti(&info);
		draw_pixel_st_en(&draw_info, &info);
		calc_draw_img_others(&draw_info, data->player, &info);
		drawing_game_img(&draw_info, game_img, \
		data->texture->img_box[info.four_dir], x);
		x++;
	}
}
