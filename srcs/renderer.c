/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:59 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/18 15:47:17 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/MLX/mlx.h"
#include "../incs/data.h"
#include "../incs/util.h"
#include <stdio.h>
#include <unistd.h>

// MLX_SYNC_IMAGE_WRITABLE
// MLX_SYNC_WIN_FLUSH_CMD
// MLX_SYNC_WIN_CMD_COMPLETED

int	renderer(t_data *data)
{
	return (0);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, NULL);
	//render screen
	//render minimap
	//render ui
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, NULL);
	(void)data;
	return (0);
}
