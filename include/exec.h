/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:47:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/20 20:25:00 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "MLX42.h"

# define PI 3.1415926535
# define WIDTH 2880
# define HEIGHT 1620
# define FOV 90
# define TURNING_ANGLE 0.0872664626
# define MINIMAP_SIZE 16
# define MINIMAP_FLOOR_COLOR 0x00000044
# define MINIMAP_WALL_COLOR 0x00FFFF44

# define NORTH 4.7123889804 // 3 * PI / 2
# define SOUTH 1.5707963268 // PI / 2
# define EAST 0
# define WEST 3.1415926535 // PI

enum e_vertical_or_horizontal
{
	VERTICAL,
	HORIZONTAL,
};

enum e_data
{
	RAY_COUNT = WIDTH,
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

typedef struct s_ray_data
{
	enum e_wall_orientation	orientation;
	mlx_image_t				*img;
	double					angle;
	double					distance;
	int						coords[2];
}	t_ray_data;

typedef struct s_loop_data
{
	t_player		player[1];
	const char		**map;
	int				map_width;
	int				map_height;
	mlx_image_t		*fov;
	t_ray_data		*rays;
	mlx_image_t		*minimap;
	mlx_t			*window;
	mlx_texture_t	*texture[4];
	char			*file_path[4];
	int				floor_color;
	int				ceiling_color;
}	t_loop_data;

/*									Exec.c									  */
int			exec(t_loop_data *data);
/*								  Cast_rays.c								  */
t_ray_data	*cast_rays(t_loop_data *data);
/*								  Draw_fov.c								  */
void		draw_fov(t_loop_data *data);
/*								  Draw_utils.c								  */
void		draw_line(mlx_image_t *img, int start[2], int end[2], int color);
void		draw_line_from_player(mlx_image_t *img, t_player *player,
				int coords[2], int color);
void		clear_image(mlx_image_t *img);
/*								Horizontal_rays.c							  */
bool		is_inside_map(int x, int y, t_loop_data *data);
int			*get_coords_horizontal_ray(t_loop_data *data, double angle);
/*								Vertical_rays.c								  */
int			*get_coords_vertical_ray(t_loop_data *data, double angle);
/*								  Keyhook.c									  */
void		player_moves(mlx_key_data_t key, void *param);
void		render_fov(void *param);
/*								  Math.c									  */
double		get_delta_x(double angle);
double		get_delta_y(double angle);
double		get_hypotenuse(int adjacent, int opposite);
int			normalize_coord_to_grid(int coord);
double		adjust_angle(double angle, int direction);
/*						Minimap_player_floor_and_ceiling.c					  */
mlx_image_t	*put_minimap(mlx_t *window, t_loop_data *data);
void		put_player(mlx_t *window, t_player player[1]);
void		redraw_player(t_player player[1]);
mlx_image_t	*put_floor_and_ceiling(mlx_t *window, int floor, int ceiling);
/*								  Movement.c								  */
void		movement(t_loop_data *data, int direction);

#endif