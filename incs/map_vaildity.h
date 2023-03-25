/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vaildity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:28:44 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/25 20:00:03 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VAILDITY_H
# define MAP_VAILDITY_H

# include "data.h"

int		map_vaildity(t_map *map_data, t_map_obj *map_obj);
int		check_outline_point(t_map *map_data, int y, int x);
int		check_four_point(t_map *map_data, int y, int x);
void	insert_map_obj(t_map_obj *map, char c, int x, int y);

#endif