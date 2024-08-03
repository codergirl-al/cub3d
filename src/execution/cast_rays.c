/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:19:53 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/03 17:33:11 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_images(mlx_t *window, t_ray_data *ray, t_loop_data *data)
{
	ray->img = mlx_new_image(window, MINIMAP_SIZE * data->map_width,
			MINIMAP_SIZE * data->map_height);
	mlx_image_to_window(window, ray->img, 0, 0);
	mlx_set_instance_depth(ray->img->instances, 27);
}

static double	get_distance_to_wall(t_player *player, int *wall_coords,
	double angle)
{
	double		distance;
	const int	player_pos[2]
		= {player->img->instances->x + PLAYER_CENTER,
		player->img->instances->y + PLAYER_CENTER};

	distance = get_hypotenuse(wall_coords[Y] - player_pos[Y], angle);
	if (distance == 0)
		distance = abs(wall_coords[X] - player_pos[X]);
	return (distance);
}

static bool	is_vertical_closer_to_player(int vertical[2], int horizontal[2],
	t_player *player, double angle)
{
	double		vertical_distance;
	double		horizontal_distance;

	vertical_distance = get_distance_to_wall(player, vertical, angle);
	horizontal_distance = get_distance_to_wall(player, horizontal, angle);
	return (vertical_distance < horizontal_distance);
}

static int	*get_closer_wall_to_player(t_loop_data *data, double angle,
	t_ray_data *ray)
{
	int			*horizontal;
	int			*vertical;

	horizontal = get_coords_horizontal_ray(data, angle);
	vertical = get_coords_vertical_ray(data, angle);
	if (is_vertical_closer_to_player(vertical, horizontal, data->player, angle))
	{
		ray->distance = get_distance_to_wall(data->player, vertical, angle);
		ray->orientation = WEST_TEXTURE;
		if (angle <= NORTH && angle >= SOUTH)
			ray->orientation = EAST_TEXTURE;
		return (vertical);
	}
	ray->distance = get_distance_to_wall(data->player, horizontal, angle);
	ray->orientation = NORTH_TEXTURE;
	if (angle <= WEST && angle >= EAST)
		ray->orientation = SOUTH_TEXTURE;
	return (horizontal);
}

t_ray_data	*cast_rays(t_loop_data *data)
{
	static t_ray_data	rays_data[RAY_COUNT];
	double				angle;
	double				angle_step;
	int					*wall_coords;
	int					i;

	if (rays_data->img == NULL)
		init_ray_images(data->window, rays_data, data);
	else
		ft_clear_image(rays_data->img);
	i = 0;
	angle_step = PI / 180;
	angle = data->player->angle - ((RAY_COUNT - 1) / 2 * angle_step);
	angle = adjust_angle(angle, 0);
	while (i < RAY_COUNT)
	{
		wall_coords = get_closer_wall_to_player(data, angle, &rays_data[i]);
		rays_data[i].angle = angle;
		draw_line_from_player(rays_data->img, data->player, wall_coords,
			0xff00ffff);
		angle += angle_step;
		angle = adjust_angle(angle, 0);
		i++;
	}
	return (rays_data);
}
