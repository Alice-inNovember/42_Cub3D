#include "../incs/data.h"

void	make_img_box(t_texture *tex)
{
	tex->img_box[0] = *tex->wall_e;
	tex->img_box[1] = *tex->wall_n;
	tex->img_box[2] = *tex->wall_w;
	tex->img_box[3] = *tex->wall_s;
}
