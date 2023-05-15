/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_img_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:23:58 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:16:43 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data_bonus.h"
#include "../../incs/util_bonus.h"
#include "../../incs/colors_bonus.h"

t_rgb	input_rgb(char *input, char op)
{
	t_rgb	r_rgb;
	char	**tmp;
	char	**rgb;

	if (input[0] != op)
		err_exit(E_MAP_RGB);
	tmp = ft_split(input, ' ');
	if (arr_len(tmp) != 2)
		err_exit(E_MAP_RGB);
	rgb = ft_split(tmp[1], ',');
	if (arr_len(rgb) != 3)
		err_exit(E_MAP_RGB);
	r_rgb = create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_arr(tmp);
	free_arr(rgb);
	return (r_rgb);
}

void	input_img(t_input *input, t_texture *tex, t_libx *mlx)
{
	tran_mlx_img(input, tex, mlx);
	make_t_images(tex);
	make_img_box(tex);
	tex->ceiling = input_rgb(input->ceiling, 'C');
	tex->floor = input_rgb(input->floor, 'F');
}
