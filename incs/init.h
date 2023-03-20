/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:01:20 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/20 19:05:29 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "data.h"

void	init_libx(t_data *data);
void	init_input(t_data *data, char *input_file);
void	init_map(t_data *data);
void	init_texture(t_data *data);
void	init_event(t_data *data);
void	init_player(t_data *data);
void	init_screen(t_data *data);

#endif