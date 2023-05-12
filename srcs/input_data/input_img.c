/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:23:58 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 19:57:38 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data.h"
#include "../../incs/util.h"
#include "../../incs/colors.h"

t_rgb	input_rgb(char *input, char op)
{
	char	**tmp;
	char	**rgb;

	if (input[0] != op)
		err_exit("Error\nInput is not vaild!");
	tmp = ft_split(input, ' ');
	if (arr_len(tmp) != 2)
		err_exit("Error\nInput is not vaild!");
	rgb = ft_split(tmp[1], ',');
	if (arr_len(rgb) != 3)
		err_exit("Error\nInput is not vaild!");
	free_arr(tmp);
	free_arr(rgb);
	return (create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[0]), ft_atoi(rgb[0])));
}

void	input_img(t_input *input, t_texture *tex, t_libx *mlx)
{
	tran_mlx_img(input, tex, mlx);
	make_t_images(tex);
	make_img_box(tex);
	tex->ceiling = input_rgb(input->ceiling, 'C');
	tex->floor = input_rgb(input->floor, 'F');
}
