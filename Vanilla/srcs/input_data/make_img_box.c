/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:24:36 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/13 16:50:34 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data.h"

void	make_img_box(t_texture *tex)
{
	tex->img_box[0] = *tex->wall_e;
	tex->img_box[1] = *tex->wall_n;
	tex->img_box[2] = *tex->wall_w;
	tex->img_box[3] = *tex->wall_s;
	tex->img_box[4] = *tex->door;
}
