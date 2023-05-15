/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util4_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:49 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:15:17 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libs/GNL/get_next_line.h"
#include "../../incs/data_bonus.h"
#include "../../incs/util_bonus.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

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
		err_exit(E_GNL);
	input[idx] = temp;
	return (input);
}
