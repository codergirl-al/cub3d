/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:53:53 by apeposhi          #+#    #+#             */
/*   Updated: 2024/05/15 01:07:59 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_h

# include "../libft/includes/libft.h"
#include <cmath>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_texture
{
	char	*path;
	int		width;
	int		height;
}			t_texture;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_settings
{
	int		sc_width;
	int		sc_height;
	double	sp_move;
	double	sp_rotation;
}				t_settings;

typedef struct s_game
{
	char		*map_data;
	char		**map;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	int			floor[3];
	int			ceiling[3];
	t_player	player;
	t_settings	settings;
}				t_game;

// validator functions
int	ft_validate_args(int argc, char **argv);

// parser functions

// utility functions
int	ft_print_err(char *message, int r_value);

#endif
