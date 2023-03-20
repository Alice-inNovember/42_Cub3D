/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:23:45 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/20 17:16:54 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX/mlx.h"
#include "../../incs/data.h"

void	init_texture(t_data *data)
{
	void	*(*png2image)(void *, char *, int *, int *);

	png2image = mlx_png_file_to_image;
	(void)data;
}
