/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:41:04 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/13 12:49:40 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	err_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	*ft_malloc(size_t size)
{
	void	*temp;

	temp = malloc(size);
	if (!temp)
		err_exit("Error\n : malloc err");
	return (temp);
}

void	ft_bzero(void *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)s)[i] = (unsigned char)0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*returnptr;
	size_t			test;

	test = count * size;
	if (size != 0 && (test / size != count))
		return ((void *)0);
	returnptr = (unsigned char *)malloc(count * size);
	if (!returnptr)
		err_exit("Error\n : malloc err");
	ft_bzero((void *)returnptr, count * size);
	return ((void *)returnptr);
}

int	is_set(char *str, char *set)
{
	size_t	i;
	size_t	j;
	size_t	test;

	i = 0;
	while (str[i])
	{
		j = 0;
		test = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				test = 1;
			j++;
		}
		if (test == 0)
			return (0);
		i++;
	}
	return (1);
}
