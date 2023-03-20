/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controll.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:41:49 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/20 15:43:30 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CONTROLL
# define PLAYER_CONTROLL

# include "data.h"

int		key_hook(int keycode, t_data *data);
int		red_button_hook(t_data *data);
void	player_rotate(t_data *data, int speed);
void	player_move(t_data *data, int speed);

#endif