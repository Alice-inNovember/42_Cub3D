/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_door_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:58:23 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 12:30:33 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../incs/data.h"
#include "../../incs/player_controll.h"

void	door_open_cloce(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (fabs(data->player->dir_x) < fabs(data->player->dir_y))
	{
		if (player->dir_y < 0)
			control_door(data->map->map, player->pos_x, player->pos_y, 0);
		else if (player->dir_y > 0)
			control_door(data->map->map, player->pos_x, player->pos_y, 1);
	}
	else
	{
		if (player->dir_x > 0)
			control_door(data->map->map, player->pos_x, player->pos_y, 2);
		else if (player->dir_x < 0)
			control_door(data->map->map, player->pos_x, player->pos_y, 3);
	}
}

void	control_door(char **map, double x, double y, int cas)
{
	int	i_x;
	int	i_y;

	i_x = (int)x;
	i_y = (int)y;
	put_number(&i_x, &i_y, cas);
	if (map[i_x][i_y] == 'M')
		map[i_x][i_y] = 'O';
	else if (map[i_x][i_y] == 'O')
	{
		if ((cas == 0 || cas == 1) && (cas_test(i_y, y, cas)))
			map[i_x][i_y] = 'M';
		if ((cas == 2 || cas == 3) && (cas_test(i_x, x, cas)))
			map[i_x][i_y] = 'M';
	}
}

void	put_number(int *i_x, int *i_y, int cas)
{
	if (cas == 0)
		*i_y -= 1;
	else if (cas == 1)
		*i_y += 1;
	else if (cas == 2)
		*i_x += 1;
	else
		*i_x -= 1;
}

int	cas_test(int num, double f_num, int cas)
{
	if (cas == 0 || cas == 3)
	{
		if (num == (int)(f_num - 0.15))
			return (0);
	}
	else
	{
		if (num == (int)(f_num + 0.15))
			return (0);
	}
	return (1);
}
