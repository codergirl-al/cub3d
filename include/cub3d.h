/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:53:53 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/12 19:12:14 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mem/libft_mem_allocation.h"
# include "libft_fd_operations.h"
# include "printf.h"
# include "libft.h"
# include "MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// typedef struct s_texture
// {
// 	char	*path;
// 	int		width;
// 	int		height;
// }			t_texture;

// typedef struct s_player
// {
// 	double	x;
// 	double	y;
// 	double	dir_x;
// 	double	dir_y;
// 	double	plane_x;
// 	double	plane_y;
// }				t_player;

// typedef struct s_settings
// {
// 	int		sc_width;
// 	int		sc_height;
// 	double	sp_move;
// 	double	sp_rotation;
// }				t_settings;

// typedef struct s_game
// {
// 	char		*map_data;
// 	char		**map;
// 	t_texture	north;
// 	t_texture	south;
// 	t_texture	east;
// 	t_texture	west;
// 	int			floor[3];
// 	int			ceiling[3];
// 	t_player	player;
// 	t_settings	settings;
// }				t_game;

typedef struct s_data
{
	char	**map_2d;
	int		rows;
	int		cols;
	int		p_x;
	int		p_y;
	int		w_map;
	int		h_map;
	char	**ff;
	char	**cc;
	int		fd;
	int		i;
	char	*line;
	char	*ture;
	char	*map;
	char	**ture2d;
	char	**sq_map;
	char	**rgb;
	// t_txtr	*t;
}	t_data;
// validator functions
int	ft_validate_args(int argc, char **argv);

// parser functions

// utility functions
int	ft_print_err(char *message, int r_value);

// cleanup 
void	ft_free_data(t_data *gd);

#endif
