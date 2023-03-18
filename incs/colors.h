/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:49:14 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/17 15:50:46 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "data.h"

t_rgb	create_trgb(int t, int r, int g, int b);
int		get_t(t_rgb trgb);
int		get_r(t_rgb trgb);
int		get_g(t_rgb trgb);
int		get_b(t_rgb trgb);

#endif