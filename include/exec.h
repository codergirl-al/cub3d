/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:47:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/25 16:41:31 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "MLX42.h"

# define PI 3.1415926535
# define WIDTH 768
# define HEIGHT 640
# define FOV 60
# define RADIAN_STEP 0.0872664626
# define MINIMAP_SIZE 16
# define MINIMAP_FLOOR_COLOR 0x00000044
# define MINIMAP_WALL_COLOR 0x00FFFF44

enum e_data
{
	RAY_COUNT = 60,
	PLAYER_CENTER = MINIMAP_SIZE / 4,
};

enum e_clockwise
{
	CLOCKWISE = -1,
	COUNTER_CLOCKWISE = 1,
};

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
	int			map_width;
	int			map_height;
	mlx_image_t	*fov;
	mlx_image_t	*rays;
	mlx_image_t	*minimap;
	mlx_t		*window;
}	t_loop_data;

void		draw_line(mlx_image_t *img, int start[2], int end[2], int color);
void		player_moves(mlx_key_data_t key, void *param);
int			put_player(mlx_t *window, t_player player[1]);
int			redraw_player(t_player player[1]);
double		get_delta_x(double angle);
double		get_delta_y(double angle);
double		adjust_angle(double angle, int direction);
int			*get_coords_horizontal_ray(t_loop_data *data, double angle);
int			*get_coords_vertical_ray(t_loop_data *data, double angle);
int			normalize_coord_to_grid(int coord);
bool		is_inside_map(int x, int y, t_loop_data *data);
mlx_image_t	*cast_rays(t_loop_data *data);
double		get_hipothenuse(int opposite, double angle);
void		movement(t_loop_data *data, int direction);
void		render_fov(void *param);

#endif