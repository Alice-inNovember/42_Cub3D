/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:24:43 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/12 14:26:47 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minimap.h"

void	find_minimap(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (i < mini->parti_y)
	{
		j = 0;
		while (j < mini->parti_x)
		{
			printf("%d %d의 영역\n", i, j);
			print_minimap(mini->mini_obj[i][j]);
			j++;
		}
		i++;
	}
}

void	print_minimap(t_mini_obj mini_obj)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 11)
		{
			printf("%d", mini_obj.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
