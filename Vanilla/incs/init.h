/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:01:20 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/25 20:11:24 by sounchoi         ###   ########.fr       */
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
void	init_map_obj(t_data *data);

#endif