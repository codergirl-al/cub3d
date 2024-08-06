/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:47:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/06 15:15:34 by JFikents         ###   ########.fr       */
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

# define NORTH 4.7123889804 // 3 * PI / 2
# define SOUTH 1.5707963268 // PI / 2
# define EAST 0
# define WEST 3.1415926535 // PI

enum e_data
{
	RAY_COUNT = FOV,
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

enum e_wall_orientation
{
	NORTH_TEXTURE,
	SOUTH_TEXTURE,
	EAST_TEXTURE,
	WEST_TEXTURE,
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

typedef struct ray_data
{
	enum e_wall_orientation	orientation;
	mlx_image_t				*img;
	double					angle;
	double					distance;
}	t_ray_data;

typedef struct s_loop_data
{
	t_player	player[1];
	const char	**map;
	int			map_width;
	int			map_height;
	mlx_image_t	*fov;
	t_ray_data	*rays;
	mlx_image_t	*minimap;
	mlx_t		*window;
}	t_loop_data;

mlx_image_t	*put_minimap(mlx_t *window, t_loop_data *data);
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
t_ray_data	*cast_rays(t_loop_data *data);
double		get_hypotenuse_with_pythagoras(int adjacent, int opposite);
void		movement(t_loop_data *data, int direction);
void		render_fov(void *param);
void		draw_fov(t_loop_data *data);
void		ft_clear_image(mlx_image_t *img);
void		draw_line_from_player(mlx_image_t *img, t_player *player,
				int coords[2], int color);

#endif