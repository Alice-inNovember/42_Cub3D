/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mini_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:24:43 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/13 16:35:29 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minimap.h"

void	make_mini_player(t_mini *mini, t_libx *mlx)
{
	int	x;
	int	y;

	y = 0;
	mini->player = malloc(sizeof(t_image) * 1);
	mini->player->img = mlx_new_image(mlx->mlx, 4, 4);
	mini->player->addr = mlx_get_data_addr(mini->player->img, \
	&mini->player->bits_per_pixel, &mini->player->line_length, \
	&mini->player->endian);
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			my_mlx_pixel_put(mini->player, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}
