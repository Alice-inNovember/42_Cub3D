#include "../../incs/input_data.h"

void	input_img(t_input *input, t_texture *tex, t_libx *mlx)
{
	tran_mlx_img(input, tex, mlx);
	make_t_images(tex);
	make_background(tex, mlx);
	make_img_box(tex);
}
