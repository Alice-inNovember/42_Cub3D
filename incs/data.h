/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:04:51 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/10 17:20:27 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define RED 0
# define GREEN 1
# define BLUE 2

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_map
{
	int		xsize;
	int		ysize;
	char	**map;
}	t_map;

typedef struct s_input
{
	char	*no_png;
	char	*so_png;
	char	*we_png;
	char	*ea_png;
	char	*floor;
	char	*ceiling;
	char	**map;
}	t_input;

typedef struct s_data
{
	t_input	*input;
}	t_data;

#endif