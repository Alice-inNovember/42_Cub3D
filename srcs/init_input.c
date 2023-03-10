/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:00:07 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/10 17:23:42 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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
		err_exit("ERR : GNL file err");
	input[idx] = temp;
	return (input);
}

void	parse_input(t_data *data, char	**inputstr, size_t i)
{
	if (inputstr[i][0] == 'N' && inputstr[i][1] == 'O')
		(void)(0);
	else if (inputstr[i][0] == 'S' && inputstr[i][1] == 'O')
		(void)(0);
	else if (inputstr[i][0] == 'W' && inputstr[i][1] == 'E')
		(void)(0);
	else if (inputstr[i][0] == 'E' && inputstr[i][1] == 'A')
		(void)(0);
	else if (inputstr[i][0] == 'F')
		(void)(0);
	else if (inputstr[i][0] == 'C')
		(void)(0);
	
}

void	init_input(t_data *data, char *input_file)
{
	int		file_fd;
	char	**inputstr;
	size_t	i;

	file_fd = open(input_file, O_RDONLY);
	if (file_fd <= 2)
		err_exit("ERR : File open faild");
	inputstr = read_file(0, file_fd);
	if (inputstr == 0)
		err_exit("ERR : init_input");
	i = 0;
	while (inputstr[i])
	{
		parse_input(data, inputstr, i);
		i++;
	}
}
