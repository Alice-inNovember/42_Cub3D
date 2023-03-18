/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vaildity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:28:44 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/17 14:28:59 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VAILDITY_H
# define MAP_VAILDITY_H

# include "data.h"

int		map_vaildity(t_map *map_data, t_map_obj *map_obj);
int		check_outline_point(t_map *map_data, int y, int x);
int		check_four_point(t_map *map_data, int y, int x);
void	map_obj_init(t_map_obj *map_obj);
void	insert_map_obj(t_map_obj *map, char c);

#endif