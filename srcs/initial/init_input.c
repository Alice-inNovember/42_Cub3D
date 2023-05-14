/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:00:07 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/14 16:36:34 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "../../incs/data.h"
#include "../../incs/util.h"
#include "../../libs/GNL/get_next_line.h"

char	**read_file(int idx, int fd)
{
	char	*temp;
	char	**input;

	temp = get_next_line(fd);
	if (temp == 0)
	{
		if (idx == 0)
			return (0);
		input = ft_malloc(sizeof(char *) * (idx + 1));
		input[idx] = 0;
		return (input);
	}
	input = read_file(idx + 1, fd);
	if (!input)
		err_exit("Error\n : GNL file err");
	input[idx] = temp;
	return (input);
}

void	parse_input(t_data *data, char	**inputstr, size_t i)
{
	if (inputstr[i][0] == 'N' && inputstr[i][1] == 'O')
		data->input->no_png = ft_strdup(inputstr[i]);
	else if (inputstr[i][0] == 'S' && inputstr[i][1] == 'O')
		data->input->so_png = ft_strdup(inputstr[i]);
	else if (inputstr[i][0] == 'W' && inputstr[i][1] == 'E')
		data->input->we_png = ft_strdup(inputstr[i]);
	else if (inputstr[i][0] == 'E' && inputstr[i][1] == 'A')
		data->input->ea_png = ft_strdup(inputstr[i]);
	else if (inputstr[i][0] == 'F')
		data->input->floor = ft_strdup(inputstr[i]);
	else if (inputstr[i][0] == 'C')
		data->input->ceiling = ft_strdup(inputstr[i]);
	else if (!is_set(inputstr[i], "\n 01NSEWM"))
		err_exit("Error\n : Map not valid");
}

void	parse_map(t_data *data, char **inputstr, size_t i, size_t cnt)
{
	while (inputstr[i])
	{
		if (inputstr[i][0] == '\n')
			(void)0;
		else if (inputstr[i][ft_strlen(inputstr[i]) - 1] == '\n')
			inputstr[i][ft_strlen(inputstr[i]) - 1] = 0;
		parse_input(data, inputstr, i);
		i++;
	}
	i = 0;
	while (inputstr[i + 1])
		i++;
	while (is_set(inputstr[i - cnt], "01 NSEWM"))
		cnt++;
	if (cnt == 0)
		err_exit("Error\n : Map not valid");
	data->input->map = ft_calloc(cnt + 1, sizeof(char *));
	cnt --;
	while (cnt != 0)
	{
		data->input->map[cnt] = ft_strdup(inputstr[i]);
		cnt--;
		i--;
	}
	data->input->map[cnt] = ft_strdup(inputstr[i]);
}

void	property_ck(t_data *data, char **inputstr)
{
	data->input->no_png = 0;
	data->input->so_png = 0;
	data->input->ea_png = 0;
	data->input->we_png = 0;
	data->input->floor = 0;
	data->input->ceiling = 0;
	parse_map(data, inputstr, 0, 0);
	if (data->input->no_png == 0)
		err_exit("Error\n : Map not valid, no path or data");
	if (data->input->so_png == 0)
		err_exit("Error\n : Map not valid, no path or data");
	if (data->input->we_png == 0)
		err_exit("Error\n : Map not valid, no path or data");
	if (data->input->ea_png == 0)
		err_exit("Error\n : Map not valid, no path or data");
	if (data->input->floor == 0)
		err_exit("Error\n : Map not valid, no path or data");
	if (data->input->ceiling == 0)
		err_exit("Error\n : Map not valid, no path or data");
}

void	init_input(t_data *data, char *input_file)
{
	int		file_fd;
	char	**inputstr;
	size_t	i;

	if (ft_strcmp(&input_file[ft_strlen(input_file) - 4], ".cub"))
		err_exit("Error\n : .cub map only");
	file_fd = open(input_file, O_RDONLY);
	if (file_fd <= 2)
		err_exit("Error\n : File open faild");
	inputstr = read_file(0, file_fd);
	if (inputstr == 0)
		err_exit("Error\n : init_input");
	property_ck(data, inputstr);
	i = 0;
	while (inputstr[i])
	{
		free(inputstr[i]);
		i++;
	}
	free(inputstr);
}
