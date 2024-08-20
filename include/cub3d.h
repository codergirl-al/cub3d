/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:53:53 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 02:43:06 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# define NORTH_TEXTURE 0
# define SOUTH_TEXTURE 1
# define EAST_TEXTURE 2
# define WEST_TEXTURE 3

typedef struct s_data
{
	char			**map_2d;
	char			*raw_data;
	int				map_rows;
	int				map_cols;
	int				player_x;
	int				player_y;
	char			player_d;
	int				map_width;
	int				map_height;
	int				f_colors[3];
	int				c_colors[3];
	int				fd;
	char			*map_data;
	char			*textures;
	char			*file_path[4];
}	t_data;

// validator functions
int		ft_validate_args(int argc, char **argv);

// parser functions
void	ft_parse(int argc, char **argv, t_data *playground);
int		ft_handle_raw_data(t_data *playground);
int		ft_handle_textures(t_data *playground);
int		ft_handle_input(t_data *playground, char *data, char flag);
int		ft_handle_map(t_data *playground);

// parser utilities
int		ft_check_ending(char *filename);
size_t	ft_arrlen(char **arr);
void	ft_arrfree(char **arr);
int		ft_digit_check(char *color);
size_t	ft_strcountchr(char *str, char c);

// utility functions
int		ft_calc_width(t_data *playground);
size_t	ft_strlen_updated(const char *s);
void	ft_assign_values(t_data *playground);

// cleanup 
void	ft_free_data(t_data *gd);
int		ft_err(t_data *playground, char *message);

#endif
