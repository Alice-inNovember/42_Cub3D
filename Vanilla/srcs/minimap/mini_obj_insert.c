/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_obj_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nemesis03_mac <nemesis03_mac@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:26:59 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/16 13:00:52 by nemesis03_m      ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minimap.h"
#include "../../incs/util.h"

int	mini_obj_insert(t_mini *mini, t_map *map_data)
{
	if (mini_obj_init(mini) == 1)
		return (1);
	mini_obj_map_insert(mini->mini_obj, map_data);
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
	mini_obj->map = (int **)ft_malloc(sizeof(int *) * 10);
	if (mini_obj->map == NULL)
		return (1);
	while (i < 10)
	{
		j = 0;
		mini_obj->map[i] = (int *)ft_malloc(sizeof(int) * 10);
		if (mini_obj->map[i] == NULL)
			return (1);
		while (j < 10)
		{
			mini_obj->map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

void	mini_obj_map_insert(t_mini_obj **mini_obj, \
t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->ysize)
	{
		j = 0;
		while (j < map_data->xsize)
		{
			if (map_data->map[i][j] == ' ' || map_data->map[i][j] == 0)
				mini_obj[i / 10][j / 10].map[i % 10][j % 10] = 0;
			else if (map_data->map[i][j] == 'M')
				mini_obj[i / 10][j / 10].map[i % 10][j % 10] = 1;
			else if (map_data->map[i][j] == '1')
				mini_obj[i / 10][j / 10].map[i % 10][j % 10] = 2;
			else
				mini_obj[i / 10][j / 10].map[i % 10][j % 10] = 3;
			j++;
		}
		i++;
	}
}
