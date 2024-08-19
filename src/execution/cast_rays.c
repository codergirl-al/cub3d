/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:19:53 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/11 14:23:40 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	*get_distances(int vertical[2], int horizontal[2],
	t_player *player)
{
	const int		player_pos[2] = {player->img->instances->x + PLAYER_CENTER,
		player->img->instances->y + PLAYER_CENTER};
	const int		adjecent[2] = {vertical[X] - player_pos[X],
		horizontal[X] - player_pos[X]};
	const int		opposite[2] = {vertical[Y] - player_pos[Y],
		horizontal[Y] - player_pos[Y]};
	static double	distance[2];

	distance[VERTICAL]
		= get_hypotenuse(adjecent[VERTICAL], opposite[VERTICAL]);
	distance[HORIZONTAL]
		= get_hypotenuse(adjecent[HORIZONTAL], opposite[HORIZONTAL]);
	return (distance);
}

static void	set_distance_and_orientation(double *distance, t_ray_data *ray)
{
	static bool	last_result;
	bool		is_vertical_smaller;

	is_vertical_smaller = distance[VERTICAL] < distance[HORIZONTAL];
	if (distance[VERTICAL] == distance[HORIZONTAL])
		is_vertical_smaller = last_result;
	if (is_vertical_smaller == true)
	{
		ray->distance = distance[VERTICAL];
		ray->orientation = WEST_TEXTURE;
		if (ray->angle <= NORTH && ray->angle >= SOUTH)
			ray->orientation = EAST_TEXTURE;
	}
	else
	{
		ray->distance = distance[HORIZONTAL];
		ray->orientation = NORTH_TEXTURE;
		if (ray->angle <= WEST && ray->angle >= EAST)
			ray->orientation = SOUTH_TEXTURE;
	}
	last_result = is_vertical_smaller;
}

static void	set_closer_wall_to_player(t_loop_data *data, t_ray_data *ray)
{
	int			*horizontal;
	int			*vertical;
	double		*distances;

	horizontal = get_coords_horizontal_ray(data, ray->angle);
	vertical = get_coords_vertical_ray(data, ray->angle);
	distances = get_distances(vertical, horizontal, data->player);
	set_distance_and_orientation(distances, ray);
	if (ray->orientation <= SOUTH_TEXTURE)
	{
		ray->coords[X] = horizontal[X];
		ray->coords[Y] = horizontal[Y];
		return ;
	}
	ray->coords[X] = vertical[X];
	ray->coords[Y] = vertical[Y];
	return ;
}

t_ray_data	*cast_rays(t_loop_data *data)
{
	static t_ray_data	rays_data[RAY_COUNT];
	double				angle;
	int					opposite;
	int					i;

	opposite = -RAY_COUNT / 2;
	i = -1;
	while (++i < RAY_COUNT)
	{
		angle = atan((double)opposite / (RAY_COUNT / 2)) + data->player->angle;
		rays_data[i].angle = adjust_angle(angle, 0);
		set_closer_wall_to_player(data, &rays_data[i]);
		opposite++;
	}
	return (rays_data);
}
/*
	? If you want to see the rays, uncomment the following lines.
	! This goes at the start of cast_rays
	if (rays_data->img == NULL)
		init_ray_images(data->window, rays_data, data);
	else
		clear_image(rays_data->img);
	! This goes in the loop
		draw_line_from_player(rays_data->img, data->player, wall_coords,
			0xff00ffff);

	! The following function goes on top of cast_rays
static void	init_ray_images(mlx_t *window, t_ray_data *ray, t_loop_data *data)
{
	ray->img = mlx_new_image(window, MINIMAP_SIZE * data->map_width,
			MINIMAP_SIZE * data->map_height);
	mlx_image_to_window(window, ray->img, 0, 0);
	mlx_set_instance_depth(ray->img->instances, 27);
}
 */
