/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:00:07 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:21:11 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include "../../incs/data.h"
#include "../../incs/util.h"

void	put_tex(char **adr, char *str)
{
	if (*adr != 0)
		err_exit(E_TEXTURED);
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = 0;
	*adr = ft_strdup(str);
}

int	is_tex(t_data *data, char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		put_tex(&data->input->no_png, str);
	else if (str[0] == 'S' && str[1] == 'O')
		put_tex(&data->input->so_png, str);
	else if (str[0] == 'E' && str[1] == 'A')
		put_tex(&data->input->ea_png, str);
	else if (str[0] == 'W' && str[1] == 'E')
		put_tex(&data->input->we_png, str);
	else if (str[0] == 'C' && str[1] == ' ')
		put_tex(&data->input->ceiling, str);
	else if (str[0] == 'F' && str[1] == ' ')
		put_tex(&data->input->floor, str);
	else
		return (0);
	return (1);
}

int	is_map(char *str)
{
	if (!is_set(str, "\n 01NSEWM"))
		return (0);
	if (str[0] == '\n')
		return (0);
	if (is_in_set(str[0], "0NSEWM\n") == 1)
		return (0);
	return (1);
}

void	parse_data(t_data *data, char **inputstr, int i, int maplen)
{
	while ((is_tex(data, inputstr[i]) || inputstr[i][0] == '\n') && inputstr[i])
		i++;
	while (inputstr[i])
	{
		if (is_map(inputstr[i]) == 0)
			err_exit(E_MAPVALID);
		i++;
	}
	i--;
	while (is_map(inputstr[i]))
	{
		maplen++;
		i--;
	}
	i++;
	data->input->map = malloc(sizeof(char *) * (maplen + 1));
	data->input->map[maplen] = 0;
	maplen = 0;
	while (inputstr[i])
	{
		data->input->map[maplen] = ft_strdup(inputstr[i]);
		maplen++;
		i++;
	}
}

void	init_input(t_data *data, char *input_file)
{
	int		file_fd;
	int		i;
	char	**inputstr;

	if (ft_strcmp(&input_file[ft_strlen(input_file) - 4], ".cub"))
		err_exit(E_EXETENSION);
	file_fd = open(input_file, O_RDONLY);
	if (file_fd <= 2)
		err_exit(E_FOPEN_FAIL);
	inputstr = read_file(0, file_fd);
	if (inputstr == 0)
		err_exit(E_MAPVALID);
	parse_data(data, inputstr, 0, 0);
	i = 0;
	while (data->input->map[i])
	{
		if (data->input->map[i][ft_strlen(data->input->map[i]) - 1] == '\n')
			data->input->map[i][ft_strlen(data->input->map[i]) - 1] = 0;
		i++;
	}
	free_arr(inputstr);
}
