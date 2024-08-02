/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:19:53 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/02 16:05:17 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_images(mlx_t *window, t_ray_data *ray)
{
	int			i;

	i = 0;
	ray->img = mlx_new_image(window, 1, 1);
	mlx_put_pixel(ray->img, 0, 0, 0xFF00FFFF);
	while (i < RAY_COUNT)
	{
		mlx_image_to_window(window, ray->img, 0, 0);
		i++;
	}
}

static int	*get_closer_wall_to_player(t_loop_data *data, double angle,
	t_ray_data *ray)
{
	int			*coords;
	int			*horizontal;
	int			*vertical;
	double		h_hypotenuse;
	const int	player_pos[2]
		= {data->player->img->instances->x + PLAYER_CENTER,
		data->player->img->instances->y + PLAYER_CENTER};

	horizontal = get_coords_horizontal_ray(data, angle);
	vertical = get_coords_vertical_ray(data, angle);
	h_hypotenuse = get_hypotenuse(horizontal[Y] - player_pos[Y], angle);
	if (h_hypotenuse == 0)
		h_hypotenuse = abs(horizontal[X] - player_pos[X]);
	coords = vertical;
	ray->distance = get_hypotenuse(vertical[Y] - player_pos[Y], angle);
	if (ray->distance == 0)
		ray->distance = abs(vertical[X] - player_pos[X]);
	ray->orientation = WEST_TEXTURE;
	if (angle <= NORTH && angle >= SOUTH)
		ray->orientation = EAST_TEXTURE;
	if (h_hypotenuse < ray->distance)
	{
		coords = horizontal;
		ray->distance = h_hypotenuse;
		ray->orientation = NORTH_TEXTURE;
		if (angle <= WEST && angle >= EAST)
			ray->orientation = SOUTH_TEXTURE;
	}
	return (coords);
}

t_ray_data	*cast_rays(t_loop_data *data)
{
	static t_ray_data	rays_data[RAY_COUNT];
	double				angle;
	double				angle_step;
	int					*wall_coords;
	int					i;

	if (rays_data->img == NULL)
		init_ray_images(data->window, rays_data);
	i = 0;
	angle_step = PI / 180;
	angle = data->player->angle - ((RAY_COUNT - 1) / 2 * angle_step);
	angle = adjust_angle(angle, 0);
	while (i < RAY_COUNT)
	{
		wall_coords = get_closer_wall_to_player(data, angle, &rays_data[i]);
		rays_data[i].angle = angle;
		rays_data->img->instances[i].x = wall_coords[X];
		rays_data->img->instances[i].y = wall_coords[Y];
		angle += angle_step;
		angle = adjust_angle(angle, 0);
		i++;
	}
	return (rays_data);
}
