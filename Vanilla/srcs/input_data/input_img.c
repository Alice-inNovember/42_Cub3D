/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:23:58 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/26 17:07:37 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/input_data.h"
#include "../../incs/util.h"
#include "../../incs/colors.h"

int		cntcoma(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while(str[i])
	{
		if (str[i] == ',')
			cnt++;
		i++;
	}
	return (cnt);
}

t_rgb	input_rgb(char *input, char op)
{
	t_rgb	r_rgb;
	char	**tmp;
	char	**rgb;

	if (input == 0)
		err_exit(E_MAP_RGB);
	if (input[0] != op)
		err_exit(E_MAP_RGB);
	tmp = ft_split(input, ' ');
	if (arr_len(tmp) != 2)
		err_exit(E_MAP_RGB);
	if (cntcoma(tmp[1]) != 3)
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
