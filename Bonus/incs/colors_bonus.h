/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:49:14 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 15:53:21 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_BONUS_H
# define COLORS_BONUS_H

# include "data_bonus.h"

t_rgb	create_trgb(int t, int r, int g, int b);
int		get_t(t_rgb trgb);
int		get_r(t_rgb trgb);
int		get_g(t_rgb trgb);
int		get_b(t_rgb trgb);

#endif