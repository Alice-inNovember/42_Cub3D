/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:28:09 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:35:57 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minimap.h"
#include "../../incs/util.h"

int	minimap(t_map *map_data, t_data *data)
{
	t_mini	*mini;

	mini = ft_malloc(sizeof(t_mini) * 1);
	if (mini_insert(map_data, mini) == 1)
		return (1);
	if (mini_obj_insert(mini, map_data) == 1)
	{
		mini_obj_free(mini, mini->parti_y);
		return (1);
	}
	if (new_image_minimap(mini, data->libx) == 1)
		return (1);
	make_mini_player(mini, data->libx);
	data->mini = mini;
	return (0);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
