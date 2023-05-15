/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:41:04 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:37:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../incs/util.h"

size_t	ft_strlen(const char *str)
{
	size_t	returni;

	returni = 0;
	while (str[returni])
		returni++;
	return (returni);
}

char	*ft_strdup(const char *s1)
{
	size_t	strl;
	char	*returnptr;
	int		i;

	strl = ft_strlen(s1);
	returnptr = (char *)ft_malloc(strl + 1);
	if (!returnptr)
		return (0);
	i = 0;
	while (s1[i])
	{
		returnptr[i] = s1[i];
		i++;
	}
	returnptr[i] = 0;
	return (returnptr);
}

void	ft_strcpy(char *to, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		to[i] = str[i];
		i++;
	}
	return ;
}

static int	ft_isspace(char in)
{
	if (in == '\t' || in == '\n' || in == '\v')
		return (1);
	if (in == '\f' || in == '\r' || in == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		returni;
	int		sign;
	int		i;

	returni = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		returni *= 10;
		returni += str[i] - '0';
		i++;
	}
	return (returni * sign);
}
