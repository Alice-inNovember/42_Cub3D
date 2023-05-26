/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:41:04 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/26 10:04:15 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../incs/util.h"
#include "../../incs/data.h"

static int	ft_issame(char a, char b)
{
	if (a == b)
		return (1);
	return (0);
}

static char	**ft_freearr(char **s_arr)
{
	int	i;

	i = 0;
	while (!s_arr[i])
	{
		free(s_arr[i]);
		i++;
	}
	free(s_arr);
	return (0);
}

static int	str_malloc(char **returnarr, char *str, char c, int count)
{
	int	i;
	int	strsize;

	strsize = 0;
	while (!ft_issame(str[strsize], c) && str[strsize])
		strsize++;
	returnarr[count] = (char *)ft_malloc(sizeof(char) * (strsize + 1));
	if (!returnarr[count])
	{
		ft_freearr(returnarr);
		return (0);
	}
	i = 0;
	while (i < strsize)
	{
		returnarr[count][i] = str[i];
		i++;
	}
	returnarr[count][i] = 0;
	return (i);
}

static int	word_malloc(char **returnarr, char *str, char c)
{
	int	count;
	int	temp;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_issame(str[i], c))
			i++;
		else
		{
			temp = str_malloc(returnarr, &str[i], c, count);
			if (!temp)
				return (0);
			i += temp;
			count++;
		}
	}
	returnarr[count] = 0;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**returnarr;
	int		wcount;
	int		i;

	if (s == 0)
		err_exit(E_MALLOC);
	i = 0;
	wcount = 0;
	while (s[i])
	{
		if (ft_issame(s[i], c))
			i++;
		else
		{
			wcount++;
			while (!ft_issame(s[i], c) && s[i])
				i++;
		}
	}
	returnarr = (char **)ft_malloc(sizeof(char *) * (wcount + 1));
	if (!returnarr)
		return (returnarr);
	word_malloc(returnarr, (char *)s, c);
	return (returnarr);
}
