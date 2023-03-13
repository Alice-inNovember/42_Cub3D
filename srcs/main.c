/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:48:15 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/13 14:05:37 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../incs/data.h"
#include "../incs/util.h"
#include "../incs/init.h"

void	init_data(t_data *data, char *input_file)
{
	data->input = ft_calloc(1, sizeof(t_input));
	init_input(data, input_file);
}

void	test_input(t_data *data)
{
	size_t	i;

	i = 0;
	printf("%s\n", data->input->no_png);
	printf("%s\n", data->input->so_png);
	printf("%s\n", data->input->ea_png);
	printf("%s\n", data->input->we_png);
	printf("%s\n", data->input->ceiling);
	printf("%s\n", data->input->floor);
	while (data->input->map[i])
	{
		printf("%s\n", data->input->map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	init_data(&data, argv[1]);
	test_input(&data);
}
