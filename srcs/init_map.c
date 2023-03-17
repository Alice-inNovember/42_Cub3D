/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:04:25 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/17 11:57:14 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/MLX/mlx.h"
#include "../incs/data.h"
#include "../incs/util.h"
#include <stddef.h>

void	init_map(t_data *data)
{
	int		i;
	size_t	maxlen;
	size_t	templen;

	i = 0;
	maxlen = 0;
	while (data->input->map[i])
	{
		templen = ft_strlen(data->input->map[i]);
		if (maxlen < templen)
			maxlen = templen;
		i++;
	}
	data->map->map = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (data->input->map[i])
	{
		data->map->map[i] = ft_calloc(maxlen + 1, sizeof(char));
		ft_memset(data->map->map[i], ' ', maxlen);
		ft_strcpy(data->map->map[i], data->input->map[i]);
		i++;
	}
	data->map->xsize = maxlen;
	data->map->ysize = i;
}
