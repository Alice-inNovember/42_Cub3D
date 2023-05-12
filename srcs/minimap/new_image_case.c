#include "../../incs/minimap.h"

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
				my_mlx_pixel_put(img, j, i, 0x55555555);
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
				my_mlx_pixel_put(img, j, i, 0x55555555);
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
				my_mlx_pixel_put(img, j, i, 0x00448844);
			j++;
		}
		i++;
	}
}

void	mini_draw_door(t_image *img, int y, int x)
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
				my_mlx_pixel_put(img, j, i, 0x00999999);
			j++;
		}
		i++;
	}
}
