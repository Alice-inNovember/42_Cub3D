/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:24:43 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/13 16:42:26 by sounchoi         ###   ########.fr       */
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
		i++;
		}
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
		while (j < 10)
		{
			printf("%d", mini_obj.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
