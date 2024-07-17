/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:47:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/17 15:56:19 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "MLX42.h"

# define PI 3.1415926535
# define PLAYER_CENTER 16
# define WIDTH 768
# define HEIGHT 640

enum e_coordinates
{
	X = 0,
	Y,
};

enum e_direction
{
	FORWARD = -1,
	BACKWARD = 1,
	LEFT,
	RIGHT,
};

typedef struct s_player
{
	double		x;
	double		y;
	double		delta_x;
	double		delta_y;
	double		angle;
	mlx_image_t	*img;
}				t_player;

typedef struct s_loop_data
{
	t_player	player[1];
	const char	**map;
	mlx_t		*window;
}	t_loop_data;

void	draw_line(const mlx_image_t *img, int start[2], int end[2], int color);
void	put_pixel(const mlx_image_t *img, int x, int y, int color);
void	player_moves(mlx_key_data_t key, void *param);
int		put_player(mlx_t *window, t_player player[1]);
int		redraw_player(t_player player[1]);
double	get_delta_x(double angle);
double	get_delta_y(double angle);
double	adjust_angle(double angle, int direction);
void	draw_horizontal_rays(t_loop_data *data, t_player *player);
void	draw_vertical_ray(t_loop_data *data, t_player *player);
int		normalize_coord_to_grid(int coord);
bool	is_inside_map(int x, int y);

#endif