/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controll_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:41:49 by junlee2           #+#    #+#             */
/*   Updated: 2023/05/15 13:09:03 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CONTROLL_BONUS_H
# define PLAYER_CONTROLL_BONUS_H

# include "data_bonus.h"

// hook_box.c
int		red_button_hook(t_data *data);
int		key_press_hook(int keycode, t_data *data);
int		key_release_hook(int keycode, t_data *data);
int		mouse_hook(int x, int y, t_data *data);
// int		key_hook(int keycode, t_data *data);

// key_player_move.c
void	move_control(t_data *data);
void	key_player_move(int keycode, t_data *data);
void	left_right(t_data *data, int x, int y);
void	up_down(t_data *data, int x, int y);
int		move_detail(char **map, double x, double y, int cas);

// key_player_rotate.c
void	key_player_rotate(int keycode, t_data *data);
void	player_rotate(t_data *data, int speed);

// mouse_set.c
void	mouse_set(int keycode, t_data *data);
void	mouse_tran_control(t_data *data);
void	mouse_speed_control(int keycode, t_data *data);

// key_door_contrl.c
void	door_open_cloce(t_data *data);
void	control_door(char **map, double x, double y, int cas);
void	put_number(int *i_x, int *i_y, int cas);
int		cas_test(int num, double f_num, int cas);

void	backstep(t_data *data);

#endif