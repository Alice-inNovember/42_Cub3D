#include "../../incs/minimap.h"

int	mini_insert(t_map *map_data, t_mini *mini)
{
	mini_init(mini);
	mini_insert_xy(map_data, mini);
	if (mini_obj_malloc(mini) == 1)
	{
		printf("%s\n", "malloc_fail..");
		return (1);
	}
	return (0);
}

void	mini_init(t_mini *mini)
{
	mini->mini_obj = NULL;
	mini->parti_x = 0;
	mini->parti_y = 0;
}

void	mini_insert_xy(t_map *map_data, t_mini *mini)
{
	mini->parti_x = map_data->xsize / 10;
	if (map_data->xsize % 10 > 0)
		mini->parti_x = mini->parti_x + 1;
	mini->parti_y = map_data->ysize / 10;
	if (map_data->ysize % 10 > 0)
		mini->parti_y = mini->parti_y + 1;
}

int	mini_obj_malloc(t_mini *mini)
{
	int	i;

	i = 0;
	mini->mini_obj = \
	(t_mini_obj **)malloc(sizeof(t_mini_obj *) * mini->parti_y);
	if (mini->mini_obj == NULL)
		return (1);
	while (i < mini->parti_y)
	{
		mini->mini_obj[i] = \
		(t_mini_obj *)malloc(sizeof(t_mini_obj) * mini->parti_x);
		if (mini->mini_obj[i] == NULL)
		{
			mini_obj_free(mini, i);
			return (1);
		}
		i++;
	}
	return (0);
}

void	mini_obj_free(t_mini *mini, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(mini->mini_obj[i]);
		i++;
	}
	free(mini->mini_obj);
}
