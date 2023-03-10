/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:48:15 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/10 16:03:43 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../incs/data.h"
#include "../incs/util.h"
#include "../incs/init.h"

void	init_data(t_data *data, char *input_file)
{
	data->input = malloc(sizeof(t_input));
	if (data->input == 0 || init_input(data, input_file) == 0)
		err_exit("malloc err");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	printf("%s", argv[1]);
	init_data(&data, argv[1]);
}
