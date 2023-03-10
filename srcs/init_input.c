/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:00:07 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/10 16:39:21 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
		return (malloc(sizeof(char *) * idx));
	input = read_file(idx + 1, fd);
	if (!input)
		err_exit("GNL file err");
	input[idx] = temp;
	return (input);
}

int	init_input(t_data *data, char *input_file)
{
	int		file_fd;
	char	**inputstr;

	file_fd = open(input_file, O_RDONLY);
	if (file_fd <= 2)
		err_exit("File open faild : ");
	inputstr = read_file(0, file_fd);
}
