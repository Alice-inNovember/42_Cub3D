/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:24:36 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 14:24:38 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data.h"

void	make_img_box(t_texture *tex)
{
	tex->img_box[0] = *tex->wall_e;
	tex->img_box[1] = *tex->wall_n;
	tex->img_box[2] = *tex->wall_w;
	tex->img_box[3] = *tex->wall_s;
}
