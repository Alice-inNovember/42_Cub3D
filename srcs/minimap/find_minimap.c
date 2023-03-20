#include "../../incs/minimap.h"

void	find_minimap(t_mini *mini)
{
	for (int i = 0; i < mini->parti_y; i++)
	{
		for (int j = 0; j < mini->parti_x; j++)
		{
			printf("%d %d의 영역\n", i, j);
			print_minimap(mini->mini_obj[i][j]);
		}
	}
}

void	print_minimap(t_mini_obj mini_obj)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			printf("%d", mini_obj.map[i][j]);
		}
		printf("\n");
	}
}
