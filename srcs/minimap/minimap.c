#include "../../incs/minimap.h"

int	minimap(t_map *map_data, t_data *data)
{
	t_mini	*mini;

	mini = malloc(sizeof(mini) * 1);
	if (mini_insert(map_data, mini) == 1)
		return (1);
	if (mini_obj_insert(mini, map_data) == 1)
	{
		mini_obj_free(mini, mini->parti_y);
		return (1);
	}
	// find_minimap(&mini);
	if (new_image_minimap(mini, data->libx) == 1)
		return (1);
	data->mini = mini;
	return (0);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	new_image_minimap(t_mini *mini, t_libx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mini->parti_y)
	{
		x = 0;
		while (x < mini->parti_x)
		{
			new_img(mini->mini_obj[y][x].map, &(mini->mini_obj[y][x].img), mlx->mlx);
			x++;
		}
		y++;
	}
	return (0);
}

int	new_img(char **map, t_image *img, void *mlx)
{
	int	i;
	int	j;
	void	(*fp[2])(t_image *, int, int);

	img->img = mlx_new_image(mlx, 150, 150);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	init_fp(fp);
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

void	init_fp(void (*fp[2])(t_image *, int, int))
{
	fp[0] = mini_draw_wall;
	fp[1] = mini_draw_floor;
	fp[2] = mini_draw_out;
}

void	mini_draw_wall(t_image *img, int y, int x)
{
	int	i;
	int	j;

	i = y * 15;
	while (i >= y * 15 && i < (y + 1) * 15)
	{
		j = x * 15;
		while (j >= x * 15 && j < (x + 1) * 15)
		{
			if (j == x * 15 || j == (x + 1) * 15 - 1 || i == y * 15 || i == (y + 1) * 15 - 1)
				my_mlx_pixel_put(img, j, i, 0x00000000);
			else
				my_mlx_pixel_put(img, j, i, 0x00C7FF96);
			j++;
		}
		i++;
	}
}

void	mini_draw_floor(t_image *img, int y, int x)
{
	int	i;
	int	j;

	i = y * 15;
	while (i >= y * 15 && i < (y + 1) * 15)
	{
		j = x * 15;
		while (j >= x * 15 && j < (x + 1) * 15)
		{
			if (j == x * 15 || j == (x + 1) * 15 - 1 || i == y * 15 || i == (y + 1) * 15 - 1)
				my_mlx_pixel_put(img, j, i, 0x00000000);
			else
				my_mlx_pixel_put(img, j, i, 0x00808080);
			j++;
		}
		i++;
	}
}

void	mini_draw_out(t_image *img, int y, int x)
{
	int	i;
	int	j;

	i = y * 15;
	while (i >= y * 15 && i < (y + 1) * 15)
	{
		j = x * 15;
		while (j >= x * 15 && j < (x + 1) * 15)
		{
			if (j == x * 15 || j == (x + 1) * 15 - 1 || i == y * 15 || i == (y + 1) * 15 - 1)
				my_mlx_pixel_put(img, j, i, 0x00000000);
			else
				my_mlx_pixel_put(img, j, i, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}