/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:23:58 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 14:47:18 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data.h"

static	void	temporary_function(t_texture *tex)
{
	tex->ceiling = 0x00003333;
	tex->floor = 0x00FFFFCC;
}

void	input_img(t_input *input, t_texture *tex, t_libx *mlx)
{
	tran_mlx_img(input, tex, mlx);
	make_t_images(tex);
	make_img_box(tex);
	temporary_function(tex);
}
