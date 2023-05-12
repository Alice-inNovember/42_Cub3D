#include "../../incs/minimap.h"

int	new_image_minimap(t_mini *mini, t_libx *mlx)
{
	int	x;
	int	y;

	y = 0;
	void	(*fp[3])(t_image *, int, int);
	init_fp(fp);
	while (y < mini->parti_y)
	{
		x = 0;
		while (x < mini->parti_x)
		{
			new_img(mini->mini_obj[y][x].map, \
			&(mini->mini_obj[y][x].img), mlx->mlx, fp);
			x++;
		}
		y++;
	}
	return (0);
}

int	new_img(char **map, t_image *img, void *mlx, void (*fp[3])(t_image *, int, int))
{
	int		i;
	int		j;

	img->img = mlx_new_image(mlx, 150, 150);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_length), &(img->endian));
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			fp[map[i][j] % 3](img, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_fp(void (*fp[3])(t_image *, int, int))
{
	fp[0] = mini_draw_wall;
	fp[1] = mini_draw_floor;
	fp[2] = mini_draw_out;
	fp[3] = mini_draw_door;
}
