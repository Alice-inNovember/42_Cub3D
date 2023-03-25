/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:59 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/25 19:07:17 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"
#include "../../incs/util.h"
#include <stdio.h>
#include <unistd.h>

// MLX_SYNC_IMAGE_WRITABLE
// MLX_SYNC_WIN_FLUSH_CMD
// MLX_SYNC_WIN_CMD_COMPLETED

void	render_screen(t_data *data)
{
	(void)data;
}

int	renderer(t_data *data)
{
	return (0);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, NULL);
	render_screen(data); // img 생산.
	mlx_put_image_to_window()  // 배경 랜더.
	mlx_put_image_to_window()  // 화면 랜더.
	mlx_put_image_to_window()  // 미니멥 렌더.
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, NULL);
	(void)data;
	return (0);
}
