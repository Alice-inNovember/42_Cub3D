/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:41:04 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/13 13:18:07 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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
	returnptr = (char *)malloc(strl + 1);
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
