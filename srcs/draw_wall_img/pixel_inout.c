#include "../../incs/draw_game_img.h"
#include "../../incs/data.h"

unsigned int	get_color(t_image *data, int x, int y)
{
	char	*dst;
	int		color;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}
