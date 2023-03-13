/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:00:07 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/13 17:57:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "../incs/data.h"
#include "../incs/util.h"
#include "../libs/GNL/get_next_line.h"

char	**read_file(int idx, int fd)
{
	char	*temp;
	char	**input;

	temp = get_next_line(fd);
	if (temp == 0)
	{
		if (idx == 0)
			return (0);
		input = ft_malloc(sizeof(char *) * idx + 1);
		input[idx] = 0;
		return (input);
	}
	input = read_file(idx + 1, fd);
	if (!input)
		err_exit("Error\n : GNL file err");
	input[idx] = temp;
	return (input);
}

int	parse_input(t_data *data, char	**inputstr, size_t i)
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
	else if (!is_set(inputstr[i], "\n 01NSEW"))
		return (1);
	return (0);
}

void	parse_map(t_data *data, char **inputstr, size_t i, size_t cnt)
{
	i = 0;
	while (inputstr[i])
	{
		inputstr[i][ft_strlen(inputstr[i]) - 1] = 0;
		if (parse_input(data, inputstr, i))
			err_exit("Error\n : Map not valid");
		i++;
	}
	i = 0;
	while (inputstr[i + 1])
		i++;
	cnt = 0;
	while (is_set(inputstr[i - cnt], "01 NSEW"))
		cnt++;
	data->input->map = ft_calloc(cnt, sizeof(char *));
	cnt -= 2;
	while (cnt != 0)
	{
		data->input->map[cnt] = ft_strdup(inputstr[i]);
		i--;
		cnt--;
	}
	data->input->map[cnt] = ft_strdup(inputstr[i]);
}

void	init_input(t_data *data, char *input_file)
{
	int		file_fd;
	char	**inputstr;
	size_t	i;

	file_fd = open(input_file, O_RDONLY);
	if (file_fd <= 2)
		err_exit("Error\n : File open faild");
	inputstr = read_file(0, file_fd);
	if (inputstr == 0)
		err_exit("Error\n : init_input");
	parse_map(data, inputstr, 0, 0);
	i = 0;
	while (inputstr[i])
	{
		free(inputstr[i]);
		i++;
	}
	free(inputstr);
}
