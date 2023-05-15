/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:44:22 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/20 17:16:54 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/data.h"

t_rgb	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(t_rgb trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(t_rgb trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(t_rgb trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(t_rgb trgb)
{
	return (trgb & 0xFF);
}
