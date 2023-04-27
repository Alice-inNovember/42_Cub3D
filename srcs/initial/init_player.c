/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:01:41 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/27 20:38:34 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data.h"
#include "../../incs/util.h"

void	init_player(t_data *data)
{
	data->player->pos_x = 4.0;
	data->player->pos_y = 15.5;
	data->player->dir_x = -1.0;
	data->player->dir_y = 0.0;
	data->player->plane_x = 0.0;
	data->player->plane_y = 0.66;
}
