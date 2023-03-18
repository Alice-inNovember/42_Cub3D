/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:04:51 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/17 15:48:54 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "../libs/MLX/mlx.h"

# define RED 0
# define GREEN 1
# define BLUE 2

typedef int	t_rgb;

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

typedef struct s_libx
{
	void	*mlx;
	void	*mlx_win;
	char	*win_name;
}	t_libx;

typedef struct s_texture
{
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	t_rgb	floor;
	t_rgb	ceiling;
}	t_texture;

typedef struct s_data
{
	t_libx	*libx;
	t_input	*input;
	t_map	*map;
}	t_data;

typedef struct s_map_obj
{
	int	player;
}	t_map_obj;

#endif