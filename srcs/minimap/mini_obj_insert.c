#include "../../incs/minimap.h"

int	mini_obj_insert(t_mini *mini, t_map *map_data)
{
	if(mini_obj_init(mini) == 1)
		return (1);
	mini_obj_map_insert(mini->mini_obj, map_data, mini);
	return (0);
}

int	mini_obj_init(t_mini *mini)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < mini->parti_y)
	{
		x = 0;
		while (x < mini->parti_x)
		{
			mini->mini_obj[y][x].img.img = NULL;
			mini->mini_obj[y][x].img.addr = NULL;
			mini->mini_obj[y][x].img.bits_per_pixel = 0;
			mini->mini_obj[y][x].img.endian = 0;
			mini->mini_obj[y][x].img.line_length = 0;
			mini->mini_obj[y][x].map = NULL;
			if (mini_obj_map_malloc(&(mini->mini_obj[y][x])) == 1)
				return (1);
			x++;
		}	
		y++;
	}
	return (0);
}

int	mini_obj_map_malloc(t_mini_obj *mini_obj)
{
	int	i;
	int	j;

	i = 0;
	mini_obj->map = (char **)malloc(sizeof(char *) * 10);
	if (mini_obj->map == NULL)
		return (1);
	while (i < 10)
	{
		j = 0;
		mini_obj->map[i] = (char *)malloc(sizeof(char) * 11);
		if (mini_obj->map[i] == NULL)
			return (1);
		while (j < 10)
		{
			mini_obj->map[i][j] = ' ';
			j++;
		}
		mini_obj->map[i][j] = 0;
		i++;
	}
	return (0);
}

void	mini_obj_map_insert(t_mini_obj **mini_obj, t_map *map_data, t_mini *mini)
{
	int	i;
	int	j;
	int max;
	
	i = 0;
	max = mini->parti_x * 10;
	while (i < map_data->ysize)
	{
		j = 0;
		while (j < map_data->xsize && map_data->map[i][j] != 0)
		{
			if (map_data->map[i][j] == ' ')
				mini_obj[i / 10][j / 10].map[i % 10][j % 10] = 2;
			else if (map_data->map[i][j] == '1')
				mini_obj[i / 10][j / 10].map[i % 10][j % 10] = 1;
			else
				mini_obj[i / 10][j / 10].map[i % 10][j % 10] = 0;
			j++;
		}
		i++;
	}
}
